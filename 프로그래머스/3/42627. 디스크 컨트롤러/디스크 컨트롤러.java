import java.util.*;

class Solution {
    /* 
        [우선순위]
        1. 작업 소요시간이 짧은 것
        2. 작업 요청시간이 빠른 것
        3. 작업 번호가 작은 것
        
        [원하는 것]
        1. 각 작업의 요청 시각과 실제 종료 시각의 합
    */
    public int solution(int[][] jobInput) {
        
        JobRequests jobRequests = new JobRequests(jobInput);
        
        int currentTime = 0;
        int totalReturnTime = 0;
        PriorityDiskController priorityDiskController = new PriorityDiskController();
        while (jobRequests.isNotEmpty() || priorityDiskController.hasNextJob()) {
            priorityDiskController.adds(jobRequests.findJobByRequestAt(currentTime));
            if (!priorityDiskController.hasNextJob() && jobRequests.isNotEmpty()) {
                currentTime = jobRequests.getRecentJobRequestAt();
                priorityDiskController.adds(jobRequests.findJobByRequestAt(currentTime));
            }
            
            Job job = priorityDiskController.getNextJob();
            // System.out.println(job.getId() + ", " + job.getRequestAt() + ", " + job.getDurationTime());
            // 작업 종료 시각 = 현재 시각 + 소요시간
            // 작업 종료 시각 - 요청 시각
            // 현재 시각 + 소요시간 - 요청 시각
            // currentTime = Math.max(currentTime, job.getRequestAt());
            // System.out.println(currentTime);
            currentTime += job.getDurationTime();
            // System.out.println(currentTime);
            // System.out.println();

            totalReturnTime += (currentTime - job.getRequestAt());
            // priorityDiskController.print();
        }
        return totalReturnTime / jobInput.length;
        
        
    }
    
    class Job {
        private final int id;
        private final int requestAt;
        private final int durationTime;
        
        Job(int id, int requestAt, int durationTime) {
            this.id = id;
            this.requestAt = requestAt;
            this.durationTime = durationTime;
        }
        
        public int getId() {
            return this.id;    
        }
        
        public int getRequestAt() {
            return this.requestAt;
        }
        
        public int getDurationTime() {
            return this.durationTime;
        }   
    }
    
    class JobRequests {
        private final LinkedList<Job> jobs;
        
        JobRequests(int[][] jobsInput) {
            this.jobs = new LinkedList<>();
            addAllJobs(this.jobs, jobsInput);
            jobs.sort((job1, job2) -> Integer.compare(job1.getRequestAt(), job2.getRequestAt()));
        }
        
        public int getRecentJobRequestAt() {
            Job firstJob = jobs.getFirst();
            return firstJob.getRequestAt();
        }
        
        public List<Job> findJobByRequestAt(int requestAt) {
            List<Job> jobByRequestAt = new LinkedList<>();
            while (!jobs.isEmpty() && jobs.getFirst().getRequestAt() <= requestAt) {
                jobByRequestAt.add(jobs.getFirst());
                jobs.removeFirst();
            }
            return jobByRequestAt;
        }
        
        public boolean isNotEmpty() {
            return !jobs.isEmpty();
        }
        
        private void addAllJobs(List<Job> jobs, int[][] jobsInput) {
            for (int id = 0; id < jobsInput.length; id++) {
                int[] job = jobsInput[id];
                jobs.add(new Job(id, job[0], job[1]));
            }
        }
    }
    
    class PriorityDiskController {
        private static final int SWAP = 1;
        private static final int NOT_SWAP = -1;
        
        private final PriorityQueue<Job> jobs;
        
        /*
            [우선순위]
            1. 작업 소요시간이 짧은 것
            2. 작업 요청시간이 빠른 것
            3. 작업 번호가 작은 것
        */
        PriorityDiskController() {
           this.jobs = new PriorityQueue<>(
               (job1, job2) -> compareJob(job1, job2)
           );
        }
        
        public void print() {
//             List<Job> temp = new LinkedList<>();
//             while (!jobs.isEmpty()) {
//                 Job now = jobs.poll();
//                 System.out.println(now.getId() + ", " + now.getRequestAt() + ", " + now.getDurationTime());
//                 temp.add(now);
//             }
//             System.out.println();
            
//             for (Job job : temp) {
//                 jobs.add(job);
//             }
        }
        
        public void addJob(Job job) {
            jobs.add(job);
        }
        
        public void adds(List<Job> jobs) {
            for (Job job : jobs) {
                this.jobs.add(job);
            }
        }
        
        public Job getNextJob() {
            return jobs.poll();
        }

        public boolean hasNextJob() {
            return !jobs.isEmpty();
        }
        
        private int compareJob(Job job1, Job job2) {

            if (job1.getDurationTime() != job2.getDurationTime()) {
                return Integer.compare(job1.getDurationTime(), job2.getDurationTime());
            }
            
            if (job1.getRequestAt() != job2.getRequestAt()) {
                return Integer.compare(job1.getRequestAt(), job2.getRequestAt());
            }
            
            return Integer.compare(job1.getId(), job2.getId());
        }
        
        private boolean isDurationTimeGreater(Job job1, Job job2) {
            if (job1.getDurationTime() == job2.getDurationTime()) {
                return false;
            }
            return job1.getDurationTime() > job2.getDurationTime();
        }
        
        private boolean isRequestLater(Job job1, Job job2) {
            if (job1.getRequestAt() == job2.getRequestAt()) {
                return false;
            }
            return job1.getRequestAt() > job2.getRequestAt();
        }
        
        private boolean isJobIdGreater(Job job1, Job job2) {
            return job1.getId() > job2.getId();
        }
    }
}
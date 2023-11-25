import java.util.*;

class Solution {
    
    private Map<String, Integer> nameIds = new HashMap<>();
    
    // 유저 신고한 사람들
    private Set<Integer>[] userReporter;
    
    public int[] solution(String[] userIds, String[] reports, int banReportCount) {
        setInitalGlobalValues(userIds);
        
        for (int i = 0; i < reports.length; i++) {
            String[] reporterReportee = reports[i].split(" ");

            int reporter = nameIds.get(reporterReportee[0]);
            int reportee = nameIds.get(reporterReportee[1]);

            userReporter[reportee].add(reporter);
        }
        
        int[] answer = new int[userIds.length];
        for (int i = 0; i < userReporter.length; i++) {
            if (userReporter[i].size() < banReportCount) {
                continue;
            }
            
            // 전송
            for (int reporter : userReporter[i]) {
                answer[reporter]++;
            }
        }
        
        return answer;
    }
    
    private void setInitalGlobalValues(String[] userIds) {
        userReporter = new Set[userIds.length];
        for (int i = 0; i < userIds.length; i++) {
            userReporter[i] = new HashSet<>();
            nameIds.put(userIds[i], i);
        }
    }
}
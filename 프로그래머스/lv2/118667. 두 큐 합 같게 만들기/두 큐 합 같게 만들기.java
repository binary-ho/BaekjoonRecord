
class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = -2;
        int[] que = new int[queue1.length + queue2.length];
        long sum = 0, sumNow = 0;
        
        int idx = 0;
        for (int num : queue1) {
            que[idx++] = num;
            sum += num;
            sumNow += num;
        }
        for (int num : queue2) {
            que[idx++] = num;
            sum += num;
        }
        if (sum%2==1) return -1;
        
        int start = 0, end = queue1.length - 1;
        answer = 0;
        
        while (answer < que.length * 2) {
            if (sumNow == sum / 2) {
                return answer;
            } else if (sumNow < sum/2) {
                if (end < que.length - 1) {
                    sumNow += que[++end];
                } else {
                    end = 0;
                    sumNow += que[end];
                }
                answer++;
            } else {
                if (start < que.length - 1) {
                    sumNow -= que[start++];
                } else {
                    start = 0;
                    sumNow -= que[start];
                }
                answer++;
            }
        }
        
        return -1;
    }
}
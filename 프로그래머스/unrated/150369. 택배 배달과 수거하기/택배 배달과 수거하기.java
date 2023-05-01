class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        int delNow = 0, pickNow = 0;
        long moveCnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (delNow < deliveries[i] || pickNow < pickups[i]) {
                delNow += cap;
                pickNow += cap;
                moveCnt += 2 * (i + 1);
            }
            
            delNow -= deliveries[i];
            pickNow -= pickups[i];
        }
        
        
        return moveCnt;
    }
}
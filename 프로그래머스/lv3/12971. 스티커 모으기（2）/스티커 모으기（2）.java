class Solution {
    
    public int solution(int sticker[]) {
        
        if (sticker.length == 1) {
            return sticker[0];
        }
        
        int answer = 0;
        // 뗐다 안 뗐다
        int[][] dp = new int[sticker.length][2];
        
        // 1. 첫 번째꺼 뗐다
        dp[0][0] = 0;
        dp[0][1] = sticker[0];
        // 마지막거 무시
        for (int i = 1; i < sticker.length - 1; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + sticker[i];
        }
        answer = Math.max(dp[sticker.length - 2][0], dp[sticker.length - 2][1]);
        
        // 2. 첫 번재꺼 안 뗏다
        dp[0][1] = 0;
        // 마지막거 무시
        for (int i = 1; i < sticker.length; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + sticker[i];
        }
        answer = Math.max(answer, dp[sticker.length - 1][1]);
        return answer;
    }
}
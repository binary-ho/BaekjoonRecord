class Solution {
    
    // 이분탐색으로 결과 추정하고 건널 수 있는지 매번 확인 -> 160만 시간 복잡도 0.016초
    public int solution(int[] stones, int k) {
        long left = 1;
        long right = 1;
        for (int i = 0; i < stones.length; i++) {
            if (right < stones[i]) {
                right = stones[i];
            }
        }
        right++;
             

        long answer = 1;
        while (left < right) {
            long mid = (left + right) / 2;
            if (traversal(mid, stones, k)) {
                if (mid == left) {
                    left = mid + 1;
                    continue;
                }
                
                left = mid;
                answer = answer < mid ? mid : answer;
            } else {
                right = mid;
            }
        }
        
        return (int) answer;
    }
    
    boolean traversal(long query, int[] stones, int k) {
        // query명 건널 수 있는가?
        int idx = 0;
        int canNotPass = 0;
        while (idx < stones.length) {
            if (stones[idx] >= query) {
                canNotPass = 0;
            } else {
                canNotPass++;
            }
            
            if (canNotPass >= k) {
                return false;
            }
            
            idx++;
        }
        
        return true;
    }
}
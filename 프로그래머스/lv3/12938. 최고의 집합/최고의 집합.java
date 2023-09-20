class Solution {
    public int[] solution(int n, int s) {
        if (n > s) {
            return new int[] {-1};
        }
        
        int elem = s / n;
        int left = s % n;
        
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            answer[i] = elem;
            if (i >= n - left) {
                answer[i]++;
            }
        }
        
        return answer;
    }
}
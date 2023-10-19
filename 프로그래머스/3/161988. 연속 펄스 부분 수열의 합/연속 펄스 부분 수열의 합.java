class Solution {
    
    // 그냥 다 곱하고, 투 포인터로 가장 큰거 찾아볼까?
    public long solution(int[] sequence) {
        
        int[][] pulse = new int[2][sequence.length];
        for (int i = 0; i < sequence.length; i++) {
            // 홀짝으로 나누는게 낫지
            // 홀일때 -1 짝일때 1
            pulse[0][i] = (i % 2 * 2) - 1;
        }
        
        for (int i = 0; i < sequence.length; i++) {
            pulse[0][i] *= sequence[i];
            pulse[1][i] = -pulse[0][i];
        }
        
        return Math.max(getMaxSum(pulse[0]), getMaxSum(pulse[1]));
    }
    
    long getMaxSum(int[] pulse) {
        long sum = pulse[0];
        long max = pulse[0];
        
        int left = 0;
        int right = 1;
        
        while (left < pulse.length) {
            if (right < pulse.length) {
                if (left == right || sum >= 0) {
                    sum += pulse[right++];
                } else {
                    sum -= pulse[left++];
                }
            } else {
                sum -= pulse[left++];
            }
            
            if (max < sum) {
                max = sum;
            }
        }
        
        return max;
    }
}
import java.util.*;

class Solution {
    
    // 10:49
    // 지워주는건 무거우니까 같이 나아가는건 어때?
    public int solution(int[] A, int[] B) {
        
        Arrays.sort(A);
        Arrays.sort(B);
        int answer = 0;
        int a = 0, b = 0;
        while (a < A.length && b < B.length) {
            if (A[a] >= B[b]) {
                b++;
            } else {
                answer++;
                a++;
                b++;
            }
        }
        
        return answer;
    }
}
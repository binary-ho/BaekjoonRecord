class Solution {
    
    boolean[][] pailn = new boolean[2501][2501];
    
    // 0 6
    // 1 5
    // 2 4
    // 3 3
    boolean test(int left, int right, String str) {
        if (left > right || str.charAt(left) != str.charAt(right)) {
            return false;
        }
        
        if (left == right || left + 1 == right || pailn[left + 1][right - 1]) {
            return pailn[left][right] = true;
        }
        
        return pailn[left + 1][right -1] = test(left + 1, right - 1, str);
    }
    
    // 8:23
    // a b c
    // abbacc
    // cabac
    // 내 팰린드롭이 끝나는 지점 다음 팰린드롭이 끝나는 지점이 나랑 같나?
    public int solution(String str) {
        int answer = 1;
        
        for (int i = 0; i < str.length(); i++) {
            pailn[i][i] = true;
        }
        
        for (int i = 0; i < str.length(); i++) {
            for (int length = 1; i + length <= str.length(); length++) {
                if (!test(i, i + length - 1, str)) {
                    continue;
                }
                
                answer = Math.max(answer, length);
            }
        }

        return answer;
    }
}
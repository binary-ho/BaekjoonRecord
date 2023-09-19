class Solution {
    // 11:50
    // 100만
    // 25만
    // 실제로 연산할 수는 없다.
    int N;
    int M;
    int[][] sum;
    int[] bias = {0, -1, 1};
    
    public int solution(int[][] board, int[][] skill) {
        N = board.length;
        M = board[0].length;
        sum = new int[N][M];
        
        // 2.5초
        for (int i = 0; i < skill.length; i++) {
            int damage = bias[skill[i][0]];
            int r1, c1, r2, c2;
            r1 = skill[i][1];
            c1 = skill[i][2];
            r2 = skill[i][3];
            c2 = skill[i][4];
            damage *= skill[i][5];
            
            // sum 칠하기
            // c2 + 1에다가 반대값 칠하고
            // r2 + 1에다가 반대값 칠하고
            // 오른쪽으로 쭉 가고, 한칸 내리고 (위에꺼 받아옴)
            sum[r1][c1] += damage;
            if (r2 + 1 < N) {
                sum[r2 + 1][c1] -= damage;
            }
            
            if (c2 + 1 < M) {
                sum[r1][c2 + 1] -= damage;
            }
            
            if (r2 + 1 < N && c2 + 1 < M) {
                sum[r2 + 1][c2 + 1] += damage;
            }
        }
        
        // sum
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < M; j++) {
                sum[i][j] += sum[i][j - 1];
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i != 0) {
                    sum[i][j] += sum[i - 1][j];
                }
                
                if (board[i][j] + sum[i][j] > 0) {
                    answer++;
                }
            }
        }

        return answer;
    }
}
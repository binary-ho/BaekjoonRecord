import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M, K, i, j, x, y;
    static int[][] rowSum;
    static long ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        rowSum = new int[N + 1][M + 1];

        for (int ii = 1; ii <= N; ii++) {
            st = new StringTokenizer(br.readLine());
            for (int jj = 1; jj <= M; jj++) {
                rowSum[ii][jj] += Integer.parseInt(st.nextToken());
                if (jj == 1) continue;
                rowSum[ii][jj] += rowSum[ii][jj -1];
            }
        }

        K = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());

        for (int ii = 0; ii < K; ii++) {
            st = new StringTokenizer(br.readLine());
            i = Integer.parseInt(st.nextToken());
            j = Integer.parseInt(st.nextToken());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            ans = 0;
            for (int jj = i; jj <= x; jj++) {
                ans += rowSum[jj][y];
                if (j == 1) continue;
                ans -= rowSum[jj][j - 1];
            }
            System.out.println(ans);
        }
    }
}

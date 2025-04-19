import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        final int N = Integer.parseInt(stringTokenizer.nextToken());
        final int M = Integer.parseInt(stringTokenizer.nextToken());
        final int R = Integer.parseInt(stringTokenizer.nextToken());

        final int[] items = new int[N + 1];
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        for (int i = 1; i <= N; i++) {
            items[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        final int[][] dp = new int[N + 1][N + 1];
        final int INF = 3001;
        for (int i = 0; i < N + 1; i++) {
            Arrays.fill(dp[i], INF);
        }

        for (int i = 0; i < R; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int a = Integer.parseInt(stringTokenizer.nextToken());
            int b = Integer.parseInt(stringTokenizer.nextToken());
            int cost = Integer.parseInt(stringTokenizer.nextToken());

            dp[a][b] = cost;
            dp[b][a] = cost;
        }

        for (int k = 0; k < N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (i == j) {
                        dp[i][j] = 0;
                        continue;
                    }

                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        // 이제 각 지역마다 M 아래면 몇개 얻을 수 있는지 구해보기
        int maxItem = 0;
        for (int i = 1; i <= N; i++) {
            int times = 0;
            for (int j = 1; j <= N; j++) {
                if (dp[i][j] > M) {
                    continue;
                }

                times += items[j];
            }
            maxItem = Math.max(maxItem, times);
        }
        System.out.println(maxItem);
    }
}


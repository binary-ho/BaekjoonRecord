
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;

    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        N = Integer.parseInt(stringTokenizer.nextToken());
        M = Integer.parseInt(stringTokenizer.nextToken());

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        String now = stringTokenizer.nextToken();

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        String answer = stringTokenizer.nextToken();

        int[][] dp = new int[N + 1][M + 1];
        for (int i = 0; i <= N; i++) dp[i][0] = i;
        for (int j = 0; j <= M; j++) dp[0][j] = j;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (isEqual(now.charAt(i - 1), answer.charAt(j - 1)))  {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }

                int value = Math.min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                value = Math.min(value, dp[i - 1][j - 1] + 1);
                dp[i][j] = value;
            }
        }
        System.out.println(dp[N][M]);
    }

    static boolean isEqual(char input, char answer) {
        if (input == 'i') {
            return answer == 'i'
                || answer == 'j'
                || answer == 'l';
        }
        
        if(input == 'v') {
            return answer == 'v'
            || answer == 'w';
        }
        return input == answer;
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static long[] AB, CD;
    static int[][] ABCD;
    static int left, right;
    static int leftCnt, rightCnt;
    static long leftTemp, rightTemp;
    static long sum, ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        ABCD = new int[4][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 4; j++) {
                ABCD[j][i] = Integer.parseInt(st.nextToken());
            }
        }

        int N2 = N * N;
        AB = new long[N2];
        CD = new long[N2];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                AB[i * N + j] = ABCD[0][i] + ABCD[1][j];
                CD[i * N + j] = ABCD[2][i] + ABCD[3][j];
            }
        }

        Arrays.sort(AB);
        Arrays.sort(CD);

        ans = 0;
        left = 0;
        right = N2 - 1;
        while (left < N2 && 0 <= right) {
            sum = AB[left] + CD[right];
            if (sum == 0) {
                leftTemp = AB[left];
                rightTemp = CD[right];

                leftCnt = rightCnt = 0;

                while (0 <= right && rightTemp == CD[right]) {
                    right--;
                    rightCnt++;
                }
                
                while (left < N2 && leftTemp == AB[left]) {
                    left++;
                    leftCnt++;
                }
                ans += (long) leftCnt * rightCnt;
            } else if (sum > 0) {
                right--;
            } else {
                left++;
            }
        }
        System.out.println(ans);
    }
}

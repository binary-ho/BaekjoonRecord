import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, X;
    static int left, right, sum, max, maxCnt;
    static int[] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        visit = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            visit[i] = Integer.parseInt(st.nextToken());
        }

        sum = 0;
        left = right = 0;
        while (right < X) {
            sum += visit[right++];
        }
        max = sum;
        maxCnt = 1;

        while (left < N) {
            if (right < N) {
                sum += visit[right++];
            }
            sum -= visit[left++];

            if (max < sum) {
                max = sum;
                maxCnt = 1;
            } else if (max == sum) {
                maxCnt++;
            }
        }

        if (max == 0) {
            System.out.println("SAD");
        } else {
            System.out.println(max);
            System.out.println(maxCnt);
        }
    }
}

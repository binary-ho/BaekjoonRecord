import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;


public class Main {
    static int N, K;
    static int[] feed;
    static long[] dp;
    static BufferedReader br;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        input();
        go();
    }

    // input
    public static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        feed = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            feed[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static void go() {
        dp = new long[N+1];
        int left = 0, right = 0;
        long sum = 0;
        // 점화식을 어떻게 세워야 하는가..............................................
        while(left < N) {
            //System.out.print(left+", "+right + ": ");
            if(sum < K && right < N) {
                //S/ystem.out.print("sum: " + sum + " -> ");
                sum += feed[right];
                //System.out.print(sum+", ");
                right++;
                dp[right] = max(dp[left], dp[right - 1]);
                //System.out.println("right++, dp[" + right + "]: " + dp[right]);
            } else {
                dp[right] = max(dp[right], dp[left] + sum - K);
                //System.out.print("sum: " + sum + " -> ");
                sum -= feed[left];
                //System.out.print(sum+", ");
                left++;
                //System.out.println("left++, dp[" + right + "]: " + dp[right]);
            }
        }
        System.out.println(dp[N]);
    }
}
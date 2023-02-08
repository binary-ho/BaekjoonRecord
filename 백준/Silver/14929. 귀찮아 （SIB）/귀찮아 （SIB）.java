
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] X;
    static int sum;
    static long ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        X = new int[N];

        st = new StringTokenizer(br.readLine());
        sum = 0;
        for (int i = 0; i < N; i++) {
            X[i] = Integer.parseInt(st.nextToken());
            sum += X[i];
        }

        ans = 0;
        for (int i =0; i < N; i++) {
            sum -= X[i];
            ans += (long) X[i] * sum;
        }
        System.out.println(ans);
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static int[] S;
    static int left = 0, right = 1, maxCnt = 0;
    static int evenCnt = 0, removeCnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        S = new int[N];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            S[i] = Integer.parseInt(st.nextToken());
        }

        if (S[0] % 2 == 0) evenCnt++;
        else removeCnt++;

        while (left < right) {
            if (maxCnt < evenCnt) maxCnt = evenCnt;
            if (right < N) {
                if (S[right] % 2 == 0) {
                    evenCnt++;
                    right++;
                } else if (removeCnt < K) {
                    removeCnt++;
                    right++;
                } else if (S[left] % 2 == 0) {
                    evenCnt--;
                    left++;
                } else {
                    removeCnt--;
                    left++;
                }
            } else {
                if (S[left] % 2 == 0) {
                    evenCnt--;
                } else {
                    removeCnt--;
                }
                left++;
            }
        }
        if (maxCnt < evenCnt) maxCnt = evenCnt;
        System.out.println(maxCnt);
    }
}

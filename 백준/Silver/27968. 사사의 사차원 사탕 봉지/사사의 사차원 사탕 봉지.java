import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    static long[] candySum = new long[300001];

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        candySum[0] = Long.parseLong(stringTokenizer.nextToken());
        for (int i = 1; i < M; i++) {
            candySum[i] = candySum[i - 1] + Long.parseLong(stringTokenizer.nextToken());
        }

        // 이분 탐색으로 찾아야해.
        int left, right, mid, ans;
        while (N-- > 0) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            long candyBaby = Long.parseLong(stringTokenizer.nextToken());
            if (candySum[M - 1] < candyBaby) {
                System.out.println("Go away!");
                continue;
            }

            left = 0;
            right = M - 1;
            ans = M - 1;
            while (left < right) {
                mid = (left + right) / 2;
                if (candySum[mid] < candyBaby) {
                    left = mid + 1;
                } else {
                    right = mid;
                    ans = Math.min(ans, mid);
                }
            }
            System.out.println(ans + 1);
        }
    }
}

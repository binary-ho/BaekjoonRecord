
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    static int[] ryanSum = new int[1000001];
    static int[] isRyan = new int[1000001];

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int K = Integer.parseInt(stringTokenizer.nextToken());

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        isRyan[0] = 2 - Integer.parseInt(stringTokenizer.nextToken());
        ryanSum[0] = isRyan[0];
        int left = 0, right = N;
        for (int i = 1; i < N; i++) {
            isRyan[i] = 2 - Integer.parseInt(stringTokenizer.nextToken());
            ryanSum[i] = ryanSum[i - 1] + isRyan[i];
            if (right == N && ryanSum[i] == K) {
                right = i;
            }
        }

        if (right == N) {
            System.out.println(-1);
            return;
        }

        // 줄일수 있다 -> 줄인다
        // 없다 옆으로 한칸
        int ans = right - left + 1;
        while (left < right && right < N) {
            int next = ryanSum[right] - ryanSum[left + 1] + isRyan[left + 1];
            if (next >= K) {
                left++;
            } else {
                right++;
            }

            if (ans > right - left + 1) {
                ans = right - left + 1;
            }
        }

        System.out.println(ans);
    }
}



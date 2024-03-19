
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;

    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        N = Integer.parseInt(stringTokenizer.nextToken());

        int[] weights = new int[N];
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        for (int i = 0; i < N; i++) {
            // 받아
            weights[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        M = Integer.parseInt(stringTokenizer.nextToken());

        int[] marbles = new int[M];
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        for (int i = 0; i < M; i++) {
            marbles[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        Arrays.sort(weights);

        int max = 40_501;
        boolean[] possible = new boolean[max];
        possible[0] = true;
        // 같은 추가 영향을 미치지 않게 하려면..
        for (int j = 0; j < N; j++) {
            int weight = weights[j];
            for (int w = (max - 1) - weight; w >= 0; w--) {
                if (!possible[w]) continue;
                possible[w + weight] = true;
            }

            // 마이너스까지 포함해야함
            for (int w = 0; w < max; w++) {
                if (!possible[w]) continue;
                possible[Math.abs(w - weight)] = true;
            }
        }

        for (int j = 0; j < M; j++) {
            int marble = marbles[j];
            char answer = possible[marble] ? 'Y' : 'N';
            System.out.print(answer);
            if (j != M - 1) System.out.print(" ");
        }
    }
}


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    private static int N;
    private static int M;
    private static int T;
    private static int K;
    private static int a;
    private static int b;
    private static int phase = 0;
    private static boolean lifeMap[][][] = new boolean[2][101][101];

    private static boolean getNextPhaseLife(int y, int x) {

        // count
        int lifeCount = 0;
        for (int i = y - K; i <= y + K; i++) {
            if (i < 0 || i >= N) continue;;
            for (int j = x - K; j <= x + K; j++) {
                if (j < 0 || j >= M) continue;
                if (i == y && j == x) continue;

                if (lifeMap[phase][i][j]) {
                    lifeCount++;
                }
            }
        }

        boolean isAlive = lifeMap[phase][y][x];

        if (isAlive) {
            return a <= lifeCount && lifeCount <= b;
        }

        return a < lifeCount && lifeCount <= b;
    }


    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        N = Integer.parseInt(stringTokenizer.nextToken());
        M = Integer.parseInt(stringTokenizer.nextToken());
        T = Integer.parseInt(stringTokenizer.nextToken());
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        K = Integer.parseInt(stringTokenizer.nextToken());
        a = Integer.parseInt(stringTokenizer.nextToken());
        b = Integer.parseInt(stringTokenizer.nextToken());

        // 페이즈 관리하자.
        // 25칸을 확인해야 한다.
        // 최악 2500 칸을 확인해야 한다.
        // 이걸 300 * 2500 -> 할만하다.
        String input;
        for (int i = 0; i < N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            input = stringTokenizer.nextToken();
            for (int j = 0; j < M; j++) {
                lifeMap[phase][i][j] = input.charAt(j) == '*';
            }
        }

        while (T-- > 0) {
            int nextPhase = 1 - phase;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    lifeMap[nextPhase][i][j] = getNextPhaseLife(i, j);
                }
            }

            phase = nextPhase;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(lifeMap[phase][i][j] ? '*' : '.');
            }
            System.out.println();
        }
    }
}




import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

class Main {

    private static int[][] dist;
    private static final int INF = Integer.MAX_VALUE / 2 - 1;


    public static void main(String[] args) throws Exception {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());

        dist = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i != j) {
                    dist[i][j] = dist[i][j] = INF;
                }
            }
        }

        while(true) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int member1 = Integer.parseInt(stringTokenizer.nextToken());
            int member2 = Integer.parseInt(stringTokenizer.nextToken());

            if (member1 == -1) {
                break;
            }

            dist[member1][member2] = 1;
            dist[member2][member1] = 1;
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int minPoint = 51;
        List<Integer> candidates = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            int memberPoint = 1;
            for (int j = 1; j <= N; j++) {
                if (memberPoint < dist[i][j]) {
                    memberPoint = dist[i][j];
                }
            }

            if (minPoint > memberPoint) {
                minPoint = memberPoint;
                candidates = new LinkedList<>();
                candidates.add(i);
            } else if (minPoint == memberPoint) {
                candidates.add(i);
            }
        }

        System.out.println(minPoint + " " + candidates.size());
        for (int candidate : candidates) {
            System.out.print(candidate + " ");
        }
    }
}

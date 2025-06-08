
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static final int SIZE = 500;
    private static final int INF = 1_000_000;
    private static final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    private static final List<Integer>[] edges = new LinkedList[SIZE];
    private static final int[][] capacity = new int[SIZE][SIZE];
    private static final int[][] flow = new int[SIZE][SIZE];
    private static final int[] prevNode = new int[SIZE];
    private static final Queue<Integer> queue = new LinkedList<>();

    /*
    * 간선, 용량, 이동 경로, 유량
    * */
    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        final int cowCount = Integer.parseInt(stringTokenizer.nextToken());
        final int barnCount = Integer.parseInt(stringTokenizer.nextToken());
        final int cowNumberStart = barnCount + 1;
        final int sink = cowCount + cowNumberStart + 1;

        for (int i = 0; i <= sink; i++) {
            if (edges[i] == null) {
                edges[i] = new LinkedList<>();
            } else {
                edges[i].clear();
            }
            Arrays.fill(capacity[i], 0);
            Arrays.fill(flow[i], 0);
        }

        // 소 -> 축사
        for (int cowNumber = cowNumberStart; cowNumber < cowNumberStart + cowCount; cowNumber++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            final int cowBarnCount = Integer.parseInt(stringTokenizer.nextToken());
            for (int i = 0; i < cowBarnCount; i++) {
                final int barn = Integer.parseInt(stringTokenizer.nextToken());
                edges[cowNumber].add(barn);
                edges[barn].add(cowNumber);
                capacity[cowNumber][barn] = 1;
            }

            // source -> 소
            edges[0].add(cowNumber);
            edges[cowNumber].add(0);
            capacity[0][cowNumber] = 1;
        }

        // 축사 -> sink
        for (int barn = 1; barn <= barnCount; barn++) {
            edges[barn].add(sink);
            edges[sink].add(barn);
            capacity[barn][sink] = 1;
        }

        calculateFlow(0, sink);
    }

    private static void calculateFlow(final int source, final int sink) {
        int answer = 0;
        while (true) {
            Arrays.fill(prevNode, 0);
            queue.clear();
            queue.add(source);

            while (!queue.isEmpty() && prevNode[sink] == 0) {
                final int current = queue.poll();
                for (int next : edges[current]) {
                    if (prevNode[next] != 0 || capacity[current][next] <= flow[current][next]) {
                        continue;
                    }

                    prevNode[next] = current;
                    queue.add(next);
                }
            }

            if (prevNode[sink] == 0) {
                break;
            }

            for (int next = sink; next != source; next = prevNode[next]) {
                int prev = prevNode[next];
                flow[prev][next]++;
                flow[next][prev]--;
            }
            answer++;
        }
        System.out.println(answer);
    }
}


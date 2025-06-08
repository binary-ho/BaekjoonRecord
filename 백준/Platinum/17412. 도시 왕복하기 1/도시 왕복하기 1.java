
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static final int SIZE = 401;
    private static final int INF = 1_000_000;
    private static final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    private static final List<Integer>[] edges = new LinkedList[SIZE];
    private static final int[][] capacities = new int[SIZE][SIZE];
    private static final int[][] flow = new int[SIZE][SIZE];
    private static final int[] trace = new int[SIZE];
    private static final Queue<Integer> queue = new LinkedList<>();

    /*
    * 간선, 용량, 이동 경로, 유량
    * */
    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        final int cityCount = Integer.parseInt(stringTokenizer.nextToken());
        final int edgeCount = Integer.parseInt(stringTokenizer.nextToken());

        for (int i = 0; i <= cityCount; i++) {
            if (edges[i] == null) {
                edges[i] = new LinkedList<>();
            } else {
                edges[i].clear();
            }
            Arrays.fill(capacities[i], 0);
            Arrays.fill(flow[i], 0);
        }

        for (int i = 0; i < edgeCount; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            final int from = Integer.parseInt(stringTokenizer.nextToken());
            final int to = Integer.parseInt(stringTokenizer.nextToken());

            edges[from].add(to);
            edges[to].add(from);
            capacities[from][to] = 1;
        }
        calculateFlow(1, 2);
    }

    private static void calculateFlow(final int source, final int sink) {
        int answer = 0;
        while (true) {
            Arrays.fill(trace, 0);
            queue.clear();
            queue.add(source);

            while (!queue.isEmpty()) {
                final int current = queue.poll();
                if (current == sink) {
                    break;
                }

                for (int next : edges[current]) {
                    if (trace[next] != 0 || capacities[current][next] <= flow[current][next]) {
                        continue;
                    }

                    trace[next] = current;
                    queue.add(next);
                }
            }

            if (trace[sink] == 0) {
                break;
            }

            int minimum = INF;
            for (int next = sink; next != source; next = trace[next]) {
                int prev = trace[next];
                minimum = Math.min(minimum, capacities[prev][next] - flow[prev][next]);
            }

            for (int next = sink; next != source; next = trace[next]) {
                int prev = trace[next];
                flow[prev][next] += minimum;
                flow[next][prev] -= minimum;
            }

            answer += minimum;
        }
        System.out.println(answer);
    }
}


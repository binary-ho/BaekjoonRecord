

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static final int INF = 1_000_000;

    private static final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    private static final List<Integer>[] edges = new LinkedList[201];
    private static final int[][] capacities = new int[201][201];
    private static final int[][] flow = new int[201][201];
    private static final int[] trace = new int[201];
    private static final Queue<Integer> queue = new LinkedList<>();
    private static StringTokenizer stringTokenizer;

    /*
    * 숫자가 작은 곳에서 큰 곳으로만 이동할 수 있다.
    * 간선, 용량, 이동 경로, 유량
    * */
    public static void main(String[] args) throws IOException {
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        final int testCaseCount = Integer.parseInt(stringTokenizer.nextToken());

        for (int i = 0; i < testCaseCount; i++) {
            System.out.println(solve());
        }
    }

    private static int solve() throws IOException {
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        final int checkpoint = Integer.parseInt(stringTokenizer.nextToken());
        final int edgeCount = Integer.parseInt(stringTokenizer.nextToken());

        for (int i = 0; i <= checkpoint; i++) {
            if (edges[i] != null) {
                edges[i].clear();
            }
            Arrays.fill(capacities[i], 0);
            Arrays.fill(flow[i], 0);
        }

        // 간선과 용량 설정
        for (int i = 0; i < edgeCount; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int from = Integer.parseInt(stringTokenizer.nextToken());
            int to = Integer.parseInt(stringTokenizer.nextToken());

            if (from > to) {
                // swap
                int temp = to;
                to = from;
                from = temp;
            }

            if (edges[from] == null) {
                edges[from] = new LinkedList<>();
            }

            if (edges[to] == null) {
                edges[to] = new LinkedList<>();
            }

            edges[from].add(to);
            edges[to].add(from);
            if (from == 1 || to == checkpoint) {
                capacities[from][to] = 1;
            } else {
                capacities[from][to] = INF;
            }
            capacities[to][from] = 0;
        }

        return calculateFlow(checkpoint);
    }

    private static int calculateFlow(final int checkPoint) {
        int answer = 0;

        while (true) {
            Arrays.fill(trace, 0);
            queue.clear();
            queue.add(1);

            while (!queue.isEmpty() && trace[checkPoint] == 0) {
                final int current = queue.poll();
                if (edges[current] == null) {
                    continue;
                }

                for (int next : edges[current]) {
                    if (trace[next] != 0 || capacities[current][next] <= flow[current][next]) {
                        continue;
                    }

                    trace[next] = current;
                    queue.add(next);
                }
            }

            if (trace[checkPoint] == 0) {
                break;
            }

            int minimum = INF;
            for (int next = checkPoint; next != 1; next = trace[next]) {
                int prev = trace[next];
                minimum = Math.min(minimum, capacities[prev][next] - flow[prev][next]);
            }

            for (int next = checkPoint; next != 1; next = trace[next]) {
                int prev = trace[next];
                flow[prev][next] += minimum;
                flow[next][prev] -= minimum;
            }
            answer += minimum;
        }
        return answer;
    }
}


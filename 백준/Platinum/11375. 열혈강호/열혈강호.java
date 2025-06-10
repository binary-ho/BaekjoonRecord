import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static final int SIZE = 2_006;
    private static final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    private static final List<Integer>[] edges = new LinkedList[SIZE];
    private static final boolean[] visited = new boolean[SIZE];
    private static final int[] workerWork = new int[SIZE];
    private static final int[] workWorker = new int[SIZE];
    private static final int NOT_MATCHED = 0;

    /*
    * 간선, 용량, 이동 경로, 유량
    * */
    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        final int workerCount = Integer.parseInt(stringTokenizer.nextToken());
        final int workCount = Integer.parseInt(stringTokenizer.nextToken());

        for (int i = 0; i <= Math.max(workCount, workerCount); i++) {
            if (edges[i] == null) {
                edges[i] = new LinkedList<>();
            }
        }

        // 직원 -> 일
        for (int worker = 1; worker <= workerCount; worker++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            final int workerWorkCount = Integer.parseInt(stringTokenizer.nextToken());
            for (int i = 0; i < workerWorkCount; i++) {
                final int work = Integer.parseInt(stringTokenizer.nextToken());
                edges[worker].add(work);
            }
        }

        /*
        * 찾는다.
        * 매칭한다.
        * */
        int answer = 0;
        for (int worker = 1; worker <= workerCount; worker++) {
            if (workerWork[worker] != 0) {
                continue;
            }

            Arrays.fill(visited, false);
            if (canMatch(worker)) {
                answer++;
            }
        }
        System.out.println(answer);
    }

    private static boolean canMatch(int worker) {
        visited[worker] = true;

        for (int work : edges[worker]) {
            // 아직 일이 매칭되지 않음
            int matchedWorker = workWorker[work];
            if (matchedWorker == NOT_MATCHED
                // 매칭은 되어있는데, 이번 탐색에서 원래 worker를 아직 만나지 못했고, 다시 다른 사람에게 매칭할 수 있을 때
                || !visited[matchedWorker] && canMatch(matchedWorker)) {
                workerWork[worker] = work;
                workWorker[work] = worker;
                return true;
            }
        }
        return false;
    }
}
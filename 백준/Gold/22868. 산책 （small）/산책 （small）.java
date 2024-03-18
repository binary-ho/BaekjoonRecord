import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static List<Integer>[] edges;
    static boolean[] check;

    static int S;
    static int E;

    public static void main(String[] args) throws IOException {
        // 5000C2 = 2500 * 4999
        // 밖 원을 하나 만들어서 무조건 갈 수 있는 곳으로 가정, 다만 한번 시행에 한번만 갈 수 있음
        // 다른 원을 최대한 방문하면서 가고 싶은거야
        // 천천은 백만 곱하기 천은 너무 커
        // 최대한 이동해봐?
        // 전부 다 해보는건 말이 안 돼

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());

        check = new boolean[N + 1];
        edges = new List[N + 1];
        for (int i = 1; i <= N; i++) {
            edges[i] = new LinkedList<>();
        }

        for (int i = 0; i < M; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int A = Integer.parseInt(stringTokenizer.nextToken());
            int B = Integer.parseInt(stringTokenizer.nextToken());
            edges[A].add(B);
            edges[B].add(A);
        }

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        S = Integer.parseInt(stringTokenizer.nextToken());
        E = Integer.parseInt(stringTokenizer.nextToken());
        for (int i = 1; i <= N; i++) {
            if (edges[i].isEmpty()) {
                continue;
            }
            edges[i].sort(
                (i1, i2) -> {
                    if (i1 > i2) {
                        return 1;
                    }
                    return -1;
                }
            );
        }

        int[] dist = new int[N + 1];
        Arrays.fill(dist, MAX);

        int[] prev = new int[N + 1];
        Arrays.fill(prev, -1);

        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(S, 0));
        dist[S] = 0;

        while (!queue.isEmpty()) {
            Node now = queue.poll();
            for (int next : edges[now.node]) {
                if (dist[next] <= now.dist + 1) continue;
                queue.add(new Node(next, now.dist + 1));
                dist[next] = now.dist + 1;
                prev[next] = now.node;
            }
        }

        // 이제 E에서 까면 된다.
        int end = E;
        while (end != -1) {
            check[end] = true;
            end = prev[end];
        }
        check[S] = false;
        queue.add(new Node(E, dist[E]));
        while (!queue.isEmpty()) {
            Node now = queue.poll();

            for (int next : edges[now.node]) {
                if (check[next]) continue;
                check[next] = true;
                queue.add(new Node(next, now.dist + 1));
                dist[next] = now.dist + 1;
            }
        }

        System.out.println(dist[S]);

//        dfs(S, 0, true);
    }

    static class Node {
        int node;
        int dist;

        Node(int node, int dist) {
            this.node = node;
            this.dist = dist;
        }
    }

    static int MAX = 100_000;
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    /*
    * 2가지 케이스로 나눈다.
    * 1. 최단거리
    * 2. 그람 찾기 + 멘헤튼 거리
    * */
    private static final int WALL = 1;
    private static final int 그람 = 2;

    private static final int[] dx = {-1, 0, 1, 0};
    private static final int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());
        int T = Integer.parseInt(stringTokenizer.nextToken());

        int[][] map = new int[N][M];
        for (int i = 0; i < N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(stringTokenizer.nextToken());
            }
        }

        int distance = Integer.MAX_VALUE;
        int[][] minimum = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                minimum[i][j] = Integer.MAX_VALUE;
            }
        }

        PriorityQueue<Node> queue = new PriorityQueue<>((n1, n2) -> {
            return n1.cost - n2.cost;
        });

        queue.add(new Node(0, 0, 0));
        minimum[0][0] = 0;

        while (!queue.isEmpty()) {
            Node now = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nextY = now.y + dy[i];
                int nextX = now.x + dx[i];
                if ((nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                || map[nextY][nextX] == WALL
                || minimum[nextY][nextX] <= now.cost + 1) {
                    continue;
                }

//                System.out.println("nextY: " + nextY + ", nextX: " + nextX + ", cost: " + (now.cost + 1));
                minimum[nextY][nextX] = now.cost + 1;
                queue.add(new Node(nextX, nextY, now.cost + 1));
                if (map[nextY][nextX] == 그람) {
                    distance = Math.min(distance, Math.abs(N - 1 - nextY) + Math.abs(M - 1 - nextX) + now.cost + 1);
                }
            }
        }
        distance = Math.min(distance, minimum[N - 1][M - 1]);
//        if (distance == Integer.MAX_VALUE) {
//            System.out.println("Fail");
//        }
        System.out.println(distance <= T ? distance : "Fail");
    }

    private static class Node {
        int x;
        int y;
        int cost;

        public Node(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }
}


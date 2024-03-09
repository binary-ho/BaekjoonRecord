
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[] dy = {0, 0, 1, -1, -1, -2, -2, -1, 1, 2, 2, 1};
    static int[] dx = {1, -1, 0, 0, -2, -1, 1, 2, 2, 1, -1, -2};
    static int move = 12;

    public static void main(String[] args) throws IOException {

        // 갈 수 있냐 없냐는 더 빠르게 갈 방법이 있냐 없냐로 따진다.
        // 초기화는 택시 거리
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int K = Integer.parseInt(stringTokenizer.nextToken());

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int W = Integer.parseInt(stringTokenizer.nextToken());
        int H = Integer.parseInt(stringTokenizer.nextToken());

        int[][] board = new int[H][W];
        for (int i = 0; i < H; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            for (int j = 0; j < W; j++) {
                board[i][j] = Integer.parseInt(stringTokenizer.nextToken());
            }
        }

        int[][][] dists = new int[H][W][K + 1];
        int maxDist = W * H + 1;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                Arrays.fill(dists[i][j], maxDist);
            }
        }

        // start
        Queue<Node> queue = new LinkedList<>();
        dists[0][0][K] = 0;
        queue.add(new Node(0, 0, 0, K));

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            int moveNow = node.k > 0 ? move : 4;
            for (int m = 0; m < moveNow; m++) {
                int y = node.y + dy[m];
                int x = node.x + dx[m];

                if (y < 0 || y >= H || x < 0 || x >= W) continue;
                if (board[y][x] == 1) continue;

                int dist = node.dist + 1;
                int k = m < 4 ? node.k : node.k - 1;

                if (dists[y][x][k] <= dist) continue;
                dists[y][x][k] = dist;

                queue.add(new Node(y, x, dist, k));
            }
        }

        int answer = maxDist;
        for (int k = 0; k <= K; k++) {
            answer = Math.min(answer, dists[H - 1][W - 1][k]);
        }

        if (answer == maxDist) {
            System.out.println(-1);
            return;
        }
        System.out.println(answer);
    }

    static class Node {
        int y;
        int x;
        int dist;
        int k;

        Node(int y, int x, int dist, int k) {
            this.y = y;
            this.x = x;
            this.dist = dist;
            this.k = k;
        }
    }
}

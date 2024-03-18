import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static int[][] board;
    static int[][] numberBoard;
    static int N;
    static int M;


    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        N = Integer.parseInt(stringTokenizer.nextToken());
        M = Integer.parseInt(stringTokenizer.nextToken());

        board = new int[N][M];
        for (int i = 0; i < N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(stringTokenizer.nextToken());
            }
        }

        int number = 1;
        Map<Integer, Integer> numberCount = new HashMap<>();
        numberBoard = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0 || numberBoard[i][j] != 0) {
                    continue;
                }
                int count = countSize(i, j, number);
                numberCount.put(number++, count);
            }
        }

        // 마킹 완료 이제 탐색

        int answer = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] != 0) continue;
                int count = 1;
                Set<Integer> check = new HashSet<>();
                // 4방 돌면서 수잡
                for (int k = 0; k < 4; k++) {
                    int y = i + dy[k];
                    int x = j + dx[k];
                    if (y < 0 || y >= N || x < 0 || x >= M) continue;
                    if (board[y][x] == 0) continue;
                    int nextNumber = numberBoard[y][x];
                    if (check.contains(nextNumber)) continue;
                    check.add(nextNumber);
                    count += numberCount.getOrDefault(nextNumber, 0);
                }
                if (answer < count) {
                    answer = count;
                }
            }
        }
        System.out.println(answer);
    }

    static int[] dy = {0, 0, -1, 1};
    static int[] dx = {1, -1, 0, 0};

    static int countSize(int i, int j, int number) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(i, j));
        numberBoard[i][j] = number;
        int count = 1;
        
        while (!queue.isEmpty()) {
            Node now = queue.poll();
            for (int k = 0; k < 4; k++) {
                int y = now.y + dy[k];
                int x = now.x + dx[k];
                if (y < 0 || y >= N || x < 0 || x >= M) continue;
                if (board[y][x] == 0 || numberBoard[y][x] != 0) continue;
                queue.add(new Node(y, x));
                numberBoard[y][x] = number;
                count++;
            }
        }
        return count;
    }

    static class Node {

        int y;
        int x;

        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}

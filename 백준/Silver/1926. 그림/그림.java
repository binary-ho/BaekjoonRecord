import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

    private static int n, m, cnt, width, max;
    private static int[] dx = new int[]{1, 0, -1, 0};
    private static int[] dy = new int[]{0, 1, 0, -1};
    private static int[][] grid;
    private static boolean[][] visit;
    private static Queue<Point> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String input = br.readLine();
        st = new StringTokenizer(input);

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        grid = new int[n][m];
        visit = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            input = br.readLine();
            st = new StringTokenizer(input);
            for (int j = 0; j < m; j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        cnt = width = max = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit[i][j] && grid[i][j] == 1) {
                    bfs(i, j);
                    cnt++;
                    if(width > max) max = width;
                    width = 0;
                }
            }
        }

        System.out.println(cnt);
        System.out.println(max);
    }

    private static void bfs(int x, int y) {
        queue.add(new Point(x, y));
        visit[x][y] = true;
        width++;

        while (!queue.isEmpty()) {
            Point poll = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = poll.x + dx[i];
                int ny = poll.y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(visit[nx][ny] || grid[nx][ny] == 0) continue;

                queue.add(new Point(nx, ny));
                visit[nx][ny] = true;
                width++;
            }
        }
    }

    static class Point{
        public final int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

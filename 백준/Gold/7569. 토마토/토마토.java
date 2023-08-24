
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

    static int M, N, H;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());


        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        // H, N, M
//        int[][][] tomatoes = new int[101][101][101];
        int[] tomatoes = new int[100_000_1];
        boolean[] check = new boolean[100_000_1];

        int leftTomatoes = 0;
        Queue<Pair> queue = new LinkedList<>();

        // 1 익음, 0 안 익음, -1 비어있음
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < M; k++) {
                    int next = getAxis(i, j, k);
                    tomatoes[next] = Integer.parseInt(st.nextToken());

                    if (tomatoes[next] == 0) {
                        leftTomatoes++;
                        continue;
                    }

                    if (tomatoes[next] == 1) {
                        queue.add(new Pair(next, 0));
                    }
                }
            }
        }

        if (leftTomatoes == 0) {
            System.out.print(0);
            return;
        }

        int dayCount = 0;
        // 익은 곳에서 시작해서 주변 익게 하기
        // 위 아래 양 옆
        // zNM + yM + x -> NM 더하고 빼기
        //
        int[] dz = {0, 0, 0, 0, 1, -1};
        int[] dy = {0, 0, 1, -1, 0, 0};
        int[] dx = {1, -1, 0, 0, 0, 0};
        
        while(!queue.isEmpty()) {
            Pair now = queue.poll();

            for (int i = 0; i < 6; i++) {
                int x = now.axis % M + dx[i];
                int y = now.axis / M % N + dy[i];
                int z = now.axis / M / N + dz[i];
                if (x < 0 || x >= M
                    || y < 0 || y >= N
                    || z < 0 || z >= H) continue;
                
                int next = getAxis(z, y, x);
                if (tomatoes[next] != 0 || check[next]) continue;

                if (dayCount < now.dayCount + 1) {
                    dayCount = now.dayCount + 1;
                }

                check[next] = true;
                tomatoes[next] = 1;
                leftTomatoes--;
                queue.add(new Pair(next, now.dayCount + 1));
            }
        }

        if (leftTomatoes > 0) {
            System.out.print(-1);
            return;
        }

        System.out.print(dayCount);
    }

    private static int getAxis(int z, int y, int x) {
        return ((z * N) + y) * M + x;
        // M으로 나눔 : zN + y
        // M으로 나눈 나머지 -> x
        // M으로 나눈 다음 N으로 나눈 나머지 -> y
        // N으로 또 나눔 : z
    }

    static class Pair {
        int axis;
        int dayCount;
        Pair(int axis, int dayCount) {
            this.axis = axis;
            this.dayCount = dayCount;
        }
    }
}



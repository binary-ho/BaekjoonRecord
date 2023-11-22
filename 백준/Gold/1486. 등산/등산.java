import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Main {

    private static int[][] map;
    private static int[][][] dist;
    private static int N;
    private static int M;
    private static int T;
    private static final int INF = Integer.MAX_VALUE / 2 - 1;
    private static final int[] dy = {0, 0, 1, -1};
    private static final int[] dx = {1, -1, 0, 0};

    public static void main(String[] args) throws Exception {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        N = Integer.parseInt(stringTokenizer.nextToken());
        M = Integer.parseInt(stringTokenizer.nextToken());

        // T만큼 차이만 이동 가능, T보다 크면 움직이지 않는다??
        T = Integer.parseInt(stringTokenizer.nextToken());
        int D = Integer.parseInt(stringTokenizer.nextToken());

        map = new int[N][M];
        int nodeCount = N * M;
        dist = new int[2][nodeCount][nodeCount];

        for (int i = 0; i < N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            String line = stringTokenizer.nextToken();
            for (int j = 0; j < line.length(); j++) {
                char charNow = line.charAt(j);
                if (charNow <= 'Z') {
                    map[i][j] = charNow - 'A';
                } else {
                    map[i][j] = charNow - 'a' + 26;
                }
            }
        }

        for (int i = 0; i < nodeCount; i++) {
            for (int j = 0; j < nodeCount; j++) {
                dist[0][i][j] = INF;
                dist[1][i][j] = INF;
            }
        }

        int floydFlag = 0;
        // 돌아오는 길까지 잊지말고 체크
        for (int i = 0; i < nodeCount; i++) {
            dist[floydFlag][i][i] = 0;
            for (int k = 0; k < 4; k++) {
                int next = getNext(i, k);
                if (next == -1) {
                    continue;
                }

                int cost = calculateCost(i, next);
                dist[floydFlag][i][next] = Math.min(dist[floydFlag][i][next], cost);
            }
        }

        for (int k = 1; k < nodeCount; k++) {
            floydFlag = 1 - floydFlag;
            for (int i = 0; i < nodeCount; i++) {
                for (int j = 0; j < nodeCount; j++) {
                    dist[floydFlag][i][j] = Math.min(dist[1 - floydFlag][i][j], dist[1 - floydFlag][i][k] + dist[1 - floydFlag][k][j]);
                }
            }
        }

        int maxHeight = map[0][0];
        for (int i = 0; i < nodeCount; i++) {
            int go = dist[floydFlag][0][i];
            int back = dist[floydFlag][i][0];
            if (go + back > D) continue;
            int height = map[i / M][i % M];
            maxHeight = Math.max(maxHeight, height);
        }

        System.out.println(maxHeight);
    }

    static int getNext(int axis, int direction) {
        int y = axis / M;
        int x = axis % M;
        int nextY = y + dy[direction];
        int nextX = x + dx[direction];
        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) {
            return -1;
        }

        return nextY * M + nextX;
    }
    static int calculateCost(int from, int to) {
        int fromY = from / M;
        int fromX = from % M;
        int toY = to / M;
        int toX = to % M;

        int dist = map[fromY][fromX] - map[toY][toX];
        if (Math.abs(dist) > T) {
            return INF;
        }

        if (dist < 0) {
            return dist * dist;
        }

        return 1;
    }
}


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
    private static int[][] dist;
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

        dist = new int[N][N];
        for (int i = 0; i < N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            for (int j = 0; j < N; j++) {
                dist[i][j] = Integer.parseInt(stringTokenizer.nextToken());
            }
        }

        // 싸이클?
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == j || k == j || k == i) continue;
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        System.out.println(-1);
                        return;
                    }
                }
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == j || k == j || k == i) continue;
                    if (dist[i][j] == dist[i][k] + dist[k][j]) {
                        dist[i][j] = INF;
                    }
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] == INF) continue;
                answer += dist[i][j];
            }
        }
        System.out.println(answer / 2);
    }
}
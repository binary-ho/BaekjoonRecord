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

    private static int[][] edges;
    private static int[][][] dist;
    private static int[][] result;


    private static int n;
    private static int m;
    private static final int INF = Integer.MAX_VALUE / 2 - 1;


    public static void main(String[] args) throws Exception {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        n = Integer.parseInt(stringTokenizer.nextToken());
        m = Integer.parseInt(stringTokenizer.nextToken());

        dist = new int[2][n + 1][n + 1];
//        edges = new int[n + 1][n + 1];
        result = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    result[i][j] = j;
                    continue;
                }
                dist[0][i][j] = dist[1][i][j] = INF;
            }
        }

        int distFlag = 0;
        for (int i = 0; i < m; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int start = Integer.parseInt(stringTokenizer.nextToken());
            int end = Integer.parseInt(stringTokenizer.nextToken());
            int cost = Integer.parseInt(stringTokenizer.nextToken());

            dist[distFlag][start][end] = cost;
            dist[distFlag][end][start] = cost;
            result[start][end] = end;
            result[end][start] = start;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[distFlag][i][j] <= dist[distFlag][i][k] + dist[distFlag][k][j]) {
                        dist[1 - distFlag][i][j] = dist[distFlag][i][j];
                    } else {
                        dist[1 - distFlag][i][j] = dist[distFlag][i][k] + dist[distFlag][k][j];
                        result[i][j] = result[i][k];
                    }
                }
            }
            distFlag = 1 - distFlag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    System.out.print("- ");
                    continue;
                }
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}
import java.util.*;

class Solution {
    // 11:39
    // 200개면 사실 다 돌려도 무방해
    // 아니면 각 지점 별로 최소 가격 아는 것도 괜찮아
    int[][] edges;
    int[][] dist;
    static int INF = 100_0001;
    
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        
        edges = dist = new int[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++) {
            Arrays.fill(edges[i], INF);
            Arrays.fill(dist[i], INF);
        }
        
        for (int i = 0; i < fares.length; i++) {
            int c = fares[i][0];
            int d = fares[i][1];
            int f = fares[i][2];
            
            edges[c][d] = f;
            edges[d][c] = f;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                    continue;
                }
                
                dist[i][j] = Math.min(edges[i][j], edges[i][1] + edges[1][j]);
            }
        }
        
        for (int k = 2; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + edges[k][j]);
                }
            }
        }
        
        int answer = 3 * INF;
        for (int point = 1; point <= n; point++) {
            if (dist[s][point] == INF
               || dist[point][a] == INF
               || dist[point][b] == INF) continue;
            
            int distNow = dist[s][point] + dist[point][a] + dist[point][b];
            answer = Math.min(answer, distNow);
        }
        
        return answer;
    }
    
    class Node {
        int num;
        int dist;
    }
}
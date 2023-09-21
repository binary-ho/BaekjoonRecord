import java.util.*;

class Solution {
    
    int maxDist = 0;
    int[] vertexCount = new int[50001];
    List<Integer>[] vertex;
    boolean[] check;
    
    // 11:28
    // bfs로 하되, 갯수를 기록해
    public int solution(int n, int[][] edge) {
        vertex = new List[n + 1];
        check = new boolean[n + 1];
        for (int i = 0; i < n + 1; i++) {
            vertex[i] = new ArrayList<Integer>();
        }
        
        for (int i = 0; i < edge.length; i++) {
            int a = edge[i][0];
            int b = edge[i][1];
            vertex[a].add(b);
            vertex[b].add(a);
        }
        
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(1, 0));
        check[1] = true;
        
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            for (int i = 0; i < vertex[node.dest].size(); i++) {
                int next = vertex[node.dest].get(i);
                if (check[next]) continue;
                check[next] = true;
                
                int nextDist = node.dist + 1;
                queue.add(new Node(next, nextDist));
                vertexCount[nextDist]++;
                if (maxDist < nextDist) {
                    maxDist = nextDist;
                }
            }
        }
        
        return vertexCount[maxDist];
    }
    
    class Node {
        int dest;
        int dist;
        Node(int dest, int dist) {
            this.dest = dest;
            this.dist = dist;
        }
    }
}
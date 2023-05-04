import java.util.*;
import static java.lang.Math.*;
class Solution {
    
    int maxSummit = -1;
    int[] intensities = new int[50001];
    ArrayList<Edge>[] edges = new ArrayList[50001];
    Set<Integer> gSet, sSet;
    Queue<Node> que;
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        int[] answer = {0, 0};
        
        gSet = new HashSet<>();
        sSet = new HashSet<>();
        
        for (int i = 0; i < 50001; i++) {
            edges[i] = new ArrayList<>();
            intensities[i] = -1;
        }
        
        que = new LinkedList<Node>();
        for (int i = 0; i < gates.length; i++) {
            gSet.add(gates[i]);
            intensities[gates[i]] = 0;
        }
        
        for (int i = 0; i < summits.length; i++) {
            sSet.add(summits[i]);
        }
        
        for (int i = 0; i < paths.length; i++) {
            edges[paths[i][0]].add(new Edge(paths[i][1], paths[i][2]));
            edges[paths[i][1]].add(new Edge(paths[i][0], paths[i][2]));
        }
        
        for (int gate : gSet) {
            que.add(new Node(gate, 0));
            while(!que.isEmpty()) {
                Node node = que.poll();

                for (int i = 0; i < edges[node.next].size(); i++) {
                    Edge edge = edges[node.next].get(i);
                    int temp = max(node.intensity, edge.cost);
                    if (intensities[edge.to] != -1 && intensities[edge.to] <= temp) {
                        continue;
                    }
                    if (gSet.contains(edge.to)) continue;
                    if (maxSummit != -1 && maxSummit < edge.cost) continue;

                    intensities[edge.to] = temp;
                    if (sSet.contains(edge.to)) {
                        if (maxSummit < intensities[edge.to]) {
                            maxSummit = intensities[edge.to];
                        }
                        continue;
                    }
                    que.add(new Node(edge.to, temp));
                }
            }
        }
        
        
        int distMin = 10_000_001;
        for (int summit : sSet) {
            if (intensities[summit] != -1 && distMin >= intensities[summit]) {
                if (distMin == intensities[summit] 
                    && answer[0] < summit) continue;
                distMin = intensities[summit];
                answer[1] = intensities[summit];
                answer[0] = summit;
            }
        }
        
        return answer;
    }
    
    class Edge {
        int to, cost;
        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }
    
    class Node {
        int next, intensity;
        Node (int next, int intensity) {
            this.next = next; 
            this.intensity = intensity;
        }
    }
}
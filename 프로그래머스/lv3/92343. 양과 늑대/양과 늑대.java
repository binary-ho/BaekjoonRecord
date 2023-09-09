import java.util.*;
class Solution {
    
    static final int SHEEP = 0;
    static final int WOLF = 1;
    
    int[] info;
    List<Integer>[] edges = new LinkedList[18];
    int maxSheep = 0;
    int cnt = 0;
    
    void travel(int node, int sheep, int wolf,  List<Integer> nodes) {
        if (info[node] == SHEEP) {
            sheep++;
        } else {
            wolf++;
        }
        
        if (sheep <= wolf) return;
        
        if (maxSheep < sheep) {
            maxSheep = sheep;
        }
        
        List<Integer> nextNodes = new LinkedList<>(nodes);
        nextNodes.remove(Integer.valueOf(node));
        for (int i = 0; i < edges[node].size(); i++) {
            nextNodes.add(edges[node].get(i));
        }
        
        for (int nextNode : nextNodes) {
            travel(nextNode, sheep, wolf, nextNodes);
        }
        
    }
    
    public int solution(int[] originalInfo, int[][] originalEdges) {
        info = originalInfo;
        
        for (int i = 0; i <= 17; i++) {
            edges[i] = new LinkedList<>();
        }
        
        for (int i = 0; i < originalEdges.length; i++) {
            edges[originalEdges[i][0]].add(originalEdges[i][1]);
        }
       
        List<Integer> nextNodes = new LinkedList<>();
        nextNodes.add(0);
        travel(0, 0, 0, nextNodes);
        return maxSheep;
    }
}
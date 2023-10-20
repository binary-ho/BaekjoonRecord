import java.util.*;

class Solution {
    
    int[] parents;
    int answer = 0;
    
    PriorityQueue<Cost> queue = new PriorityQueue<>(
        (Cost cost0, Cost cost1) -> {
            if (cost0.cost > cost1.cost) {
                return 1;
            } else {
                return -1;
            }
        });
    
    public int solution(int n, int[][] costs) {
        
        parents = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parents[i] = i;
        }
        
        for (int i = 0; i < costs.length; i++) {
            int[] cost = costs[i];
            queue.add(new Cost(cost[0], cost[1], cost[2]));
        }
        
        while (!queue.isEmpty()) {
            queue.poll().union();
        }
        
        return answer;
    }
    
    int find(int child) {
        if (parents[child] == child) {
            return child;
        }
        
        return parents[child] = find(parents[child]);
    }
    
    
    
    class Cost {
        int from;
        int to;
        int cost;
        
        Cost(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
        
        void union() {
            int parent0 = find(this.from);
            int parent1 = find(this.to);

            if (parent0 == parent1) {
                return;
            }

            parents[parent0] = parent1;
            answer += this.cost;
        }
    }
}
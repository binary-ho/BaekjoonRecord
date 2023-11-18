import java.util.*;

class Solution {
    // 10 : 31 start
    // 하나의 규칙을 지키느라, 다른 규칙을 어기게 되는 경우가 있으면 안 된다.
    // 모든 규칙을 지킬 수 있는가? 20만개의 노드
    // 경로가 있기만 하면 된다. 최적일 필요는 없다.
    // 10만개를 직접 탐색해본다?
    // 다 돌되, 현재 방문할 수 없는 곳은 보류한다?
    List<Integer>[] edges;
    Integer[] orderMap;
    Integer[] nextOrder;
    boolean[] check;
    boolean[] isPush;
    
    int count = 0;
    int size = 1;
    
    public boolean solution(int n, int[][] paths, int[][] orders) {
        check = new boolean[n];
        isPush = new boolean[n];
        edges = new LinkedList[n];
        orderMap = new Integer[n];
        nextOrder = new Integer[n];
        Arrays.fill(orderMap, -1);
        Arrays.fill(nextOrder, -1);
        
        for (int i = 0; i < n; i++) {
            edges[i] = new LinkedList<>();
        }
        
        for (int[] path : paths) {
            edges[path[0]].add(path[1]);
            edges[path[1]].add(path[0]);
        }
        
        for (int[] order : orders) {
            orderMap[order[1]] = order[0];
            nextOrder[order[0]] = order[1];
        }
        
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        isPush[0] = true;
        
        while (!queue.isEmpty()) {
            Integer node = queue.poll();
            
            if (!go(queue, node)) {
                return false;
            }
        }
        
        
        for (boolean checkNow : check) {
            if (!checkNow) {
                return false;
            }
        }
        
        return true;
    }
    
    private boolean go(Queue<Integer> queue, Integer node) {
        size = Math.max(size, queue.size());
        
        if (count++ == size + 1) {
            return false;
        }

        if (check[node]) {
            return true;
        }

        Integer preNode = orderMap[node];
        if (preNode != -1 && !check[preNode]) {
            queue.add(node);
            return true;
        }

        check[node] = true;
        count = 0;
        addNode(queue, node);

        Integer nextNode = nextOrder[node];
        if (nextNode != -1 && !check[nextNode] && isPush[nextNode]) {
            // addNode(queue, nextNode);
            // return go(queue, nextNode);
            for (Integer edge : edges[nextNode]) {
                go(queue, edge);
            }
        }
        return true;
    }
    
    private void addNode(Queue<Integer> queue, Integer node) {
        for (Integer edge : edges[node]) {
            if (check[edge]) {
                continue;
            }

            queue.add(edge);
            isPush[edge] = true;
        }
    }
}
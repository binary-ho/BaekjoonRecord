import java.util.*;

class Solution {
    
    // 1시 48분
    // 제곱들의 합이므로 최대한 값을 비슷하게 낮춘다.
    public long solution(int n, int[] works) {
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < works.length; i++) {
            queue.add(-works[i]);
        }
        
        while (n > 0) {
            Integer top = queue.poll();
            
            if (top == 0) {
                queue.add(top);
                break;
            }
            
            n--;
            queue.add(++top);
        }
        
        long ans = 0;
        while (!queue.isEmpty()) {
            Integer top = queue.poll();
            ans += top * top;
        }
        
        return ans;
    }
}
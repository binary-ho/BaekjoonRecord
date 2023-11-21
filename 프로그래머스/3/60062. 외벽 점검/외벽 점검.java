import java.util.*;
import java.util.stream.*;

class Solution {
    
    // n 200
    // weak 15 밖에 안 된다.
    // 꾸물 꾸물 움직일 수는 없나?
    int n;
    
    Set<Integer> weaks;
    int[] dists;
    int answer = 9;
    
    boolean[] check;
    
    void go(int[] start) {
        
        check = new boolean[201];
        int answerCount = 0;
        int memberCount = 0;
        for (int i = start.length - 1; i >= 0; i--) {
            // 정답 갯수 세기
            int right = start[i];
            int moveCount = 0;
            while (moveCount++ <= dists[i]) {
                if (weaks.contains(right) && !check[right]) {
                    check[right] = true;
                    answerCount++;
                }
                right++;
                if (right == n) {
                    right = 0;
                }
            }
            memberCount++;
            if (answerCount == weaks.size()) {
                // 다 찾은거야
                answer = Math.min(answer, memberCount);
                return;
            }
        }
    }
    
    void dfs(int index, int[] weak, boolean[] check, int answerCount) {
        if (answerCount == weak.length) {
            answer = Math.min(answer, dists.length - index - 1);
            return;
        }
        
        if (index == -1) {
            return;
        }
        
        for (int i = 0; i < weak.length; i++) {
            if (check[weak[i]]) continue;
            int newAnswerCount = answerCount;
            List<Integer> list = new LinkedList<>();
            // if ((check & (1 << i)) > 0) {
            //     continue;
            // }
            
            int right = weak[i];
            int moveCount = 0;
            while (moveCount++ <= dists[index]) {
                if (weaks.contains(right) && !check[right]) {
                    check[right] = true;
                    newAnswerCount++;
                    list.add(right);
                }
                right++;
                if (right == n) {
                    right = 0;
                }
            }
            
            // dfs(index - 1, weak, start, check | (1 << i));
            dfs(index - 1, weak, check, newAnswerCount);
            
            for (int ii : list) {
                check[ii] = false;
            }
        }
    }
    
    public int solution(int nOrigin, int[] weak, int[] distsOrigin) {
        n = nOrigin;
        dists = distsOrigin;
        Arrays.sort(dists);
        
        weaks = Arrays.stream(weak)
            .boxed()
            .collect(Collectors.toSet());
        
        dfs(dists.length - 1, weak, new boolean[201], 0);
        if (answer == 9) {
            return -1;
        }
        
        return answer;
    }
}
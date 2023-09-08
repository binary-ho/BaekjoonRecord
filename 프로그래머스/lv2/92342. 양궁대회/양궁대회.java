class Solution {
    // 더 많이 맞춘 사람이 해당 점수 가져감
    // 같은 경우엔 어피치
    // 최종 같으면 어피치
    
    // Q 가장 크게 이기는 법
    // 일단 몇 점인지 알아야 하고,
    // 뺐으면 사실상 2배 먹는 것
    // 먹으면 1배 먹는 것
    // 최대한 점수를 뺐는게 유리하다
    // 화살 갯수가 같은 이상, 10 부터 쭉 이동하면서 뺐거나 넘어간다.
    // 이걸 뺐는 경우 이길 수 있나 확인
    // 안 뺐고 넘어가는게 오히려 이득일 때도 있지
    // 근데 어차피 11!이 약 3천만이니까 충분하다. 고민 X
    
    int maxScore = 0;
    int[] answer = new int[11];
    int[] ryan = new int[11];
    int[] apeach = new int[11];
    
//     void battle(int rTotal) {
//         int aScore = 0;
//         int rScore = rTotal;
//         for (int k = 0; k <= 10; k++) {
//             if (ryan[k] == 0 && apeach[k] == 0) continue;
            
//             if (ryan[k] <= apeach[k]) {
//                 aScore += 10 - k;
//                 if (ryan[k] > 0) {
//                     rScore -= 10 - k;
//                 } 
//             }
            
//             if (rScore < aScore || maxScore > rScore) {
//                 return;
//             }
//         }
        
//         if (maxScore < rScore) {
//             maxScore = rScore;
//             System.out.println(maxScore);
            
//             for (int i = 0; i <= 10; i++) {
//                 answer[i] = ryan[i];
//             }
//         }
//     }
    
//     void dfs(int depth, int n, int rTotal) {
//         if (depth == n) {
//             if (rTotal > maxScore) {
//                 battle(rTotal);
//             }
//             return;
//         }
        
//         for (int i = 0; i <= 10; i++) {
//             ryan[i]++;
//             if (ryan[i] == 1) {
//                 dfs(depth + 1, n, rTotal + (10 - i));
//             } else {
//                 dfs(depth + 1, n, rTotal);
//             }
//             ryan[i]--;
//         }
//         return;
//     }
    
    // 매번 먹으냐 안 먹느냐. 먹느냐는 정말 최소로 먹는다.
    
    void copy() {
        for (int i = 0; i <= 10; i++) {
            answer[i] = ryan[i];
        }
    }
    
    void dfs(int index, int leftArrow, int diff) {
        if (index == 11) {
            if (diff < maxScore) return;
            
            if (leftArrow > 0) {
               ryan[10] += leftArrow; 
            }
            
            if (maxScore < diff) {
                maxScore = diff;
                copy();
            } else {
                for (int i = 10; i >= 0; i--) {
                    if (answer[i] > ryan[i]) {
                        break;
                    } else if (answer[i] < ryan[i]) {
                        copy();
                        break;
                    }
                }
            }
            
            if (leftArrow > 0) {
               ryan[10] -= leftArrow; 
            }
            
            return;
        }
        
        // 먹을 수 있을때, 먹을 때
        if (leftArrow > apeach[index]) {
            
            ryan[index] = apeach[index] + 1;
            int newDiff = diff + (10 - index);
            if (apeach[index] > 0) {
                newDiff += (10 - index);
            }
            
            dfs(index + 1, 
                 leftArrow - ryan[index], 
                 newDiff);
            
            ryan[index] = 0;
        }
        
        // 안 먹을 때
        dfs(index + 1, leftArrow, diff);
    }
    
    public int[] solution(int n, int[] info) {
        apeach = info;
        int totalApeach = 0;
        for (int i = 0; i <= 10; i++) {
            if (info[i] == 0) continue;
            totalApeach -= (10 - i);
        }
        
        dfs(0, n, totalApeach);
        
        if (maxScore == 0) {
            int[] lose = new int[1];
            lose[0] = -1;
            return lose;
        }
        return answer;
    }
}
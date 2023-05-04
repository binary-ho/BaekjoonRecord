import static java.lang.Math.*;

class Solution {
    
    // 기준 부터 끝까지 조사
    int[][] time = new int[200][200];
    int maxAlp = 0, maxCop = 0;
    
    public int solution(int alp, int cop, int[][] problems) {
        int answer = 0;
        
        int[][] pros = new int[problems.length + 2][5];
        
        int idx;
        for (idx = 0; idx < problems.length; idx++) {
            pros[idx] = problems[idx];
            if (maxAlp < problems[idx][0]) {
                maxAlp = problems[idx][0];
            }
            
            if (maxCop < problems[idx][1]) {
                maxCop = problems[idx][1];
            }
        }
        
        // pros[idx] = {0, 0, 1, 0, 1};
        pros[idx][0] = 0;
        pros[idx][1] = 0;
        pros[idx][2] = 1;
        pros[idx][3] = 0;
        pros[idx][4] = 1;
        
        pros[idx + 1][0] = 0;
        pros[idx + 1][1] = 0;
        pros[idx + 1][2] = 0;
        pros[idx + 1][3] = 1;
        pros[idx + 1][4] = 1;
        // pros[idx + 1] = {0, 0, 0, 1, 1};
        dfs(alp, cop, 0, pros);
        
        
        return time[maxAlp][maxCop];
    }
    
    private void dfs(int alp, int cop, int timeNow, int[][] pros) {
        if (time[alp][cop] != 0 && time[alp][cop] <= timeNow) {
            return;
        }

        time[alp][cop] = timeNow;
        
        
        for (int[] pro : pros) {
            if (alp < pro[0] || cop < pro[1]) continue;
            dfs(min(maxAlp, alp + pro[2]), min(maxCop, cop + pro[3]), timeNow + pro[4], pros);
        }
    }
}
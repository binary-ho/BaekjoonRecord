import static java.lang.Math.*;

class Solution {
    
    // 기준 부터 끝까지 조사
    int[][] time = new int[151][151];
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
        
        // 끝 2개에 그냥 공부하는 케이스를 넣었다.
        // 공부해서 알고력 높히기, 공부해서 코딩력 높히기
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

        dfs(alp, cop, 0, pros);
        return time[maxAlp][maxCop];
    }
    
    private void dfs(int alp, int cop, int timeNow, int[][] pros) {
        
        // 이미 도달해 본적 있는 점수인데, 더 나은 선택지를 알고 있다면 탐색하지 않는다.
        if (time[alp][cop] != 0 && time[alp][cop] <= timeNow) {
            return;
        }
        
        // 이 알고력과 코딩력에 도달하기까지 timeNow의 시간이 걸렸습니다.
        time[alp][cop] = timeNow;
        
        for (int[] pro : pros) {
            // 못푸는 문제는 넘어간다.
            if (alp < pro[0] || cop < pro[1]) continue;
            
            // 모든 문제를 푸는 것이 목적이기 때문에,
            // 값을 무한으로 키울 필요가 없다. 그래서 maxApl, maxCop을 대입한 것이다.
            dfs(min(maxAlp, alp + pro[2]), min(maxCop, cop + pro[3]), timeNow + pro[4], pros);
        }
    }
}
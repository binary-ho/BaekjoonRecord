#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<int> vec1, vector<int> vec2) {
    return vec1[0] < vec2[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 요청 시간, 소요 시간
    sort(jobs.begin(), jobs.end());
    
    pair<int, int> temp;
    int idx = 0;
    int timeNow = 0;
    priority_queue<pair<int, int>> que;
    
    while (idx < jobs.size() || !que.empty()) {
        
        if (que.empty() && jobs[idx][0] > timeNow) {
            timeNow = jobs[idx][0];
            que.push({-jobs[idx][1], jobs[idx][0]});
            idx++;
            continue;
        }
        
        // 지금 시간 - 요청 시간 + 소요 시간 -> 총 소요 시간
        while(idx < jobs.size() && jobs[idx][0] <= timeNow) {
            que.push({-jobs[idx][1], jobs[idx][0]});
            idx++;
        }
        
        if (!que.empty()) {
            temp = que.top();
            que.pop();
            answer += (timeNow - temp.second + (-temp.first));
            timeNow += (-temp.first);
        }
    }
    
    return answer / jobs.size();
}
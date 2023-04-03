#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> que[2];
    int queNow = 0, today = 0;
    
    for (int i = 0; i < progresses.size(); i++) {
        if (progresses[i] + speeds[i] >= 100 && que[queNow].empty()) {
            today++;
            continue;
        }
        que[queNow].push({progresses[i] + speeds[i], speeds[i]});
    }
    if (today != 0) {
        answer.push_back(today);
    }
    
    pair<int, int> pairNow;
    while (!que[0].empty() || !que[1].empty()) {
        today = 0;
        while (!que[queNow].empty()) {
            pairNow = que[queNow].front();
            que[queNow].pop();
            if (pairNow.first + pairNow.second >= 100 
                && que[1 - queNow].empty()) {
                today++;
                continue;
            }
            que[1 - queNow].push({pairNow.first + pairNow.second, pairNow.second});
        }
        if (today != 0) {
            answer.push_back(today);
        }
        queNow = 1 - queNow;
    }
    
    
    return answer;
}
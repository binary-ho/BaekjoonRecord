#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    // index priority
    queue<pair<int, int>> que;
    int maxNow = 0;
    for (int i = 0; i < priorities.size(); i++) {
        que.push({i, priorities[i]});
    }
    
    int turn = 1;
    
    while (!que.empty()) {
        maxNow = 0;
        for (int i = 0; i < que.size(); i++) {
            if (maxNow < que.front().second) {
                maxNow = que.front().second;
            }
            que.push(que.front());
            que.pop();            
        }
        
        if (maxNow > que.front().second) {
            que.push(que.front());
        }

        
        if (maxNow == que.front().second) {
            if (que.front().first == location) {
                return turn;
            }
            turn++;
        }
        
        que.pop();
    }
    
    return turn;
}
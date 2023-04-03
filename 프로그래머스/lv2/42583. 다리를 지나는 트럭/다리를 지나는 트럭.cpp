#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int seconds, weightNow, cntNow, truckNow, queSizeNow;
    seconds = weightNow = cntNow = truckNow = 0;
    
    // 위치, wegiht
    queue<pair<int, int>> que;
    
    while (truckNow < truck_weights.size()) {
        queSizeNow = que.size();
        for (int i = 0; i < queSizeNow; i++) {
            if (que.front().first == bridge_length) {
                weightNow -= que.front().second;
                cntNow--;
            } else {
                que.push({que.front().first + 1, que.front().second});
            }
            que.pop();
        }
        
        if (weight >= weightNow + truck_weights[truckNow]
           && bridge_length > cntNow) {
            que.push({1, truck_weights[truckNow]});
            weightNow += truck_weights[truckNow];
            cntNow++;
            truckNow++;
        }
        seconds++;
    }
    
    while (!que.empty()) {
        queSizeNow = que.size();
        for (int i = 0; i < queSizeNow; i++) {
            if (que.front().first != bridge_length) {
                que.push({que.front().first + 1, que.front().second});
            }
            que.pop();
        }      
        seconds++;
    }
    return seconds;
}
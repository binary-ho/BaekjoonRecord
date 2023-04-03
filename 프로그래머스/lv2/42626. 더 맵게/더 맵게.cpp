#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> que;
    
    for (int num : scoville) {
        que.push(-num);
    }
    
    int temp;
    while(que.size() > 1) {
        if (-que.top() >= K) {
            return answer;
        }
        
        temp = -que.top();
        que.pop();
        que.push(-temp + 2 * (que.top()));
        que.pop();
        
        answer++;
    }
    
    if (!que.empty() && -que.top() >= K) {
        return answer;
    } else {
        return -1;
    }
}
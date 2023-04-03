#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    /* 
    인덱스랑 price 넣고 뺑뻉이 
    떨어졌다 -> 탈락, 아니다 -> 계속 값 상승 */ 
    vector<int> answer(prices.size(), 1);
    queue<pair<int, int>> que;
    int queSizeNow, price;
    
    for (int i = 0; i < prices.size() - 1; i++) {
        price = prices[i];
        
        queSizeNow = que.size();
        for (int j = 0; j < queSizeNow; j++) {
            if (que.front().second <= price) {
                answer[que.front().first]++;
                que.push(que.front());
            }
            que.pop();
        }
        
        que.push({i, price});
    }
    answer[answer.size() - 1] = 0;
    return answer;
}
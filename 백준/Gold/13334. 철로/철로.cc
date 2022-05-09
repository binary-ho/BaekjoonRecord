#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include <map>

using namespace std;


int main() {
    int N, left, right, d;
    cin >> N;
    vector<pair<int, int>> vec(N, {0, 0});
    // 정렬을 바꿔보자 오른쪽이 더 가까울 수록 왼 쪽에 놓자.
    for(int i = 0; i < N; i++) {
        cin >> left >> right;
        if(left > right) vec[i] = {left, right};
        else vec[i] = {right, left};
    }
    sort(vec.begin(), vec.end());
    cin >> d;
    priority_queue<int> que;
    queue<int> temp;
    int ans = 0, cnt = 0;
    for(int i = 0; i < N; i++) {
        if(vec[i].first - vec[i].second> d) continue;
        while(!que.empty() && vec[i].first + que.top() > d) {
            que.pop();
        }
        que.push(-vec[i].second);
        cnt = que.size();
        if(ans < cnt) {
            ans = cnt;
            /*cout << ans << " ";
            while(!que.empty()) {
                cout << -que.top() << " ";
                temp.push(que.top());
                que.pop();
            }
            while(!temp.empty()) {
                que.push(temp.front());
                temp.pop();
            }
            cout << '\n';*/
        }
    }
    cout << ans << '\n';

    return 0;
}
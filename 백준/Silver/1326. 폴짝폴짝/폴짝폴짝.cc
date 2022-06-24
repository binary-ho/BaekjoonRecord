#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int N, a, b, mod_left;
bool check[10001];

int main() {
    cin >> N;
    vector<int> bridge(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> bridge[i];
    }
    cin >> a >> b;

    // index, cnt
    queue<pair<int, int>> que;
    que.push({a,0});
    check[a] = true;
    int idx_now, cnt_now;
    while(!que.empty()) {
        idx_now = que.front().first;
        cnt_now = que.front().second;
        que.pop();
        mod_left = abs((b - idx_now))%bridge[idx_now];
        if(mod_left == 0) {
            cout << cnt_now + 1 << '\n';
            return 0;
        } else {
            for(int i = idx_now; i <= N; i += bridge[idx_now]) {
                if(check[i]) continue;
                check[i] = true;
                que.push({i, cnt_now+1});
            }
            for(int i = idx_now; i >= 1; i -= bridge[idx_now]) {
                if(check[i]) continue;
                check[i] = true;
                que.push({i, cnt_now+1});
            }
        }
        // 한번에 못 가면.. 갈 수 있는 곳은 다 가는게 맞는거 같은데;
    }
    cout << -1 << '\n';
}
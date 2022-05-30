#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, L;

int main() {
    cin >> N >> L;
    vector<pair<int, int>> vec(N, {0,0});
    for(int i = 0; i< N; i++) {
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    int bridge_now = 0, ans = 0, cnt;
    for(int i = 0; i < N;i++) {
        if(bridge_now < vec[i].first) {
            bridge_now = vec[i].first;
        }
        cnt = (vec[i].second - bridge_now) / L;
        if(bridge_now + cnt*L < vec[i].second) cnt++;
        ans += cnt;
        bridge_now += cnt*L;
    }
    cout << ans;
}
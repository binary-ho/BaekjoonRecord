#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
priority_queue<int> que;
bool assign(vector<pair<int, int>> &vec, int limit) {
    que = {};
    for (auto p : vec) {
        if (!que.empty() && -que.top() <= p.first) que.pop();
        que.push(-p.second);
        if (que.size() > limit) return false;
    }
    return true;
}


int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end());
    int left = 0, right = N;
    int mid, ans = N;

    while (left <= right) {
        mid = (left + right) / 2;
        if (assign(vec, mid)) {
            right = mid - 1;
            if (ans > mid) ans = mid;
            continue;
        }
        left = mid + 1;
    }
    cout << ans;
}
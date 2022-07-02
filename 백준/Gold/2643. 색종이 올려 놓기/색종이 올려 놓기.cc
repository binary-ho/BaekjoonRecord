#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[101];
int main() {
    int N, a, b;
    vector<pair<int, int>> vec;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        if(a < b) vec.emplace_back(a, b);
        else vec.emplace_back(b, a);
    }
    sort(vec.begin(), vec.end());

    int max_dp, idx, ans = 1;
    for(int i = 0; i < N; i++) {
        max_dp = 0;
        idx = 0;
        for(int j = 0; j < i; j++) {
            if(vec[i].second >= vec[j].second && max_dp < dp[j]) {
                max_dp = dp[j];
            }
        }
        dp[i] = max_dp + 1;
        if(ans < dp[i]) ans = dp[i];
    }
    cout << ans;
}

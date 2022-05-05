#include <iostream>
#include <vector>

using namespace std;
bool dp[2501][2501];
int N, sum;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    vector<int> hamburgers(N, 0);
    sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> hamburgers[i];
        sum += hamburgers[i];
    }
    int hamburger;
    for(int i = 0; i < N; i++) {
        hamburger = hamburgers[i];
        if(i == 0) {
            dp[0][0] = true;
            dp[0][hamburger] = true;
            dp[hamburger][0] = true;
            continue;
        }
        // 이번 꺼를 선1 선2 나 이렇게 3명이 먹을 수 있음
        for(int j = sum; j >= 0; j--) {
            for(int k = sum; k >= 0; k--) {
                if(!dp[j][k]) continue;
                dp[j + hamburger][k] = true;
                dp[j][k+hamburger] = true;
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= sum; j++) {
        for(int k = 0; k <= sum; k++) {
            if(!dp[j][k]) continue;
            if(j < sum - j - k || k < sum - j - k || ans >= sum - j - k) continue;
            ans = sum - j - k;
        }
    }
    cout << ans;
}

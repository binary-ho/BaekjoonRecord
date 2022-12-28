#include <iostream>
using namespace std;
int N, stairs[301];
int dp[301][3];

// 0 안 밟은 케이스
// 1 직전 밟고 나 밟고
// 2칸 전 밟고 나 밟고
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> stairs[i];
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = stairs[0];

    dp[1][0] = dp[0][1];
    dp[1][1] = dp[0][1] + stairs[1];
    dp[1][2] = stairs[1];

    for (int i = 2; i < N; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][2] + stairs[i];
        dp[i][2] = max(dp[i-2][1], dp[i-2][2]) + stairs[i];
//        cout << i << ": " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';
    }
    cout << max(dp[N-1][1], dp[N-1][2]);
}

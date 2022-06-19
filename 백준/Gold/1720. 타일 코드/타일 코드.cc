#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, dp[31];
int main() {
    dp[1] = 1;
    dp[2] = 3;
    cin >> N;
    for(int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + 2*dp[i-2];
    }
    if(N==2) {
        cout << 3;
        return 0;
    }
    if(N%2==1) {
        // dp[N] - (d[N] - dp[(N-1)/2])/2
        cout << dp[N] - (dp[N] - dp[(N-1)/2])/2 << '\n';
    } else {
        // (dp[N] - (dp[N/2] + dp[(N-2)/2]))/2;
        cout << dp[N] - (dp[N] - (dp[N/2] + 2*dp[(N-2)/2]))/2 << '\n';
    }
}
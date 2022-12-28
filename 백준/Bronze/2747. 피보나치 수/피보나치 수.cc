#include <iostream>
using namespace std;
long long N, dp[46];
int main() {
    cin >> N;
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N];
}

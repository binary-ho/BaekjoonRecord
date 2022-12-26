#include <iostream>

using namespace std;

int N, K;
int coin[101], dp[10001];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - coin[i] < 0) continue;
            dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[K];
}

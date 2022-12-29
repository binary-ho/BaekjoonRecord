#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int dp[10001];
int main() {
    int N, K, input;
    cin >> N >> K;
    for (int i = 0; i <= K; i++) dp[i] = INF;
    vector<int> coinVector;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input > K) continue;
        coinVector.emplace_back(input);
        dp[input] = 1;
    }
    std::sort(coinVector.begin(), coinVector.end(), less<>());
    coinVector.erase(unique(coinVector.begin(), coinVector.end()), coinVector.end());

    for (int price = 1; price <= K; price++) {
        for (int coin : coinVector) {
            if (price - coin <= 0) continue;
            dp[price] = min(dp[price], dp[price - coin] + 1);
        }
    }
    if (dp[K] != INF) cout << dp[K];
    else cout << -1;
}

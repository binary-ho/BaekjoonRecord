#include <iostream>
#include <vector>
#define MOD 1234567
using namespace std;
long long dp[1001][10], T;
vector<int> friends[10] = {{7}, {2, 4}, {1,3,5}, {2,6}, {1,5,7}, {2,4,6,8}, {3,5,9},{4,8,0}, {5,7,9},{6,8}};

int main() {
    int temp = 1, N;
    for(int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    long long ans;
    cin >> T;
    while(T--) {
        ans = 0;
        cin >> N;
        if(temp < N) {
            for(int i = temp + 1; i <= N; i++) {
                for(int j = 0; j < 10; j++) {
                    for(int k = 0; k < friends[j].size(); k++) {
                        dp[i][j] += dp[i-1][friends[j][k]];
                    }
                    if(dp[i][j] >= MOD) dp[i][j] %= MOD;
                    //cout << i << " " << j << " " << dp[i][j]  << '\n';
                }
            }
            temp = N;
        }

        for(int i = 0; i < 10; i++) {
            ans += dp[N][i];
            if(ans >= MOD) ans %= MOD;
        }
        cout << ans << '\n';
    }
}

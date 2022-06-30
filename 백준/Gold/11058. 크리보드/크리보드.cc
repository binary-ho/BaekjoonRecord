#include <iostream>
#include <vector>

using namespace std;
long long dp[105];
int main() {
    long long N, charPerType = 1, nextCharPerType, temp;
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;
    // dp[i]가 있고
    for(long long i = 2; i <= N; i++) {
        charPerType = dp[i];
        temp = charPerType*2;
        for(long long j = i + 3; j <= N; j++) {
            if(dp[j] < temp) dp[j] = temp;
            temp += charPerType;
        }
    }
    cout << dp[N] <<'\n';
}
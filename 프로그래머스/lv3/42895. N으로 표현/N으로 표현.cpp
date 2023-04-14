#include <string>
#include <vector>
#define MAX 100000
#define INF 987654321
using namespace std;

// 흠.. 붙이기, 더하기, 빼기, 나누기, 곱하기
// 2 11 3
int dp[MAX];
int solution(int N, int number) {
    for (int i = 0; i <= MAX; i++) dp[i] = INF;
    
    long long temp;
    // 이어 붙인 꼴
    temp = N;
    for (int i = 1; i <= 8; i++) {
        dp[temp] = i;
        temp *= 10;
        temp += N;
        if (temp > MAX) break;
    }
    // 이제 부터는 min 걸어야 한다
    // 곱하는건 15번이면 충분해
    // 나누는것도 15번이면 충분해
    // 더하기 나누기는 10번만 하자 됨

    for (int k = 0; k < 4; k++) {
        temp = N;
        for (int i = 1; i <= 8; i++) {
            dp[temp] = min(dp[temp], i);
            for (int j = 0; j < MAX; j++) {
                if (dp[j] == INF) continue;
                if (j * temp < MAX) {
                    dp[j * temp] = min(dp[j * temp], dp[j] + i);
                }

                if (j % temp == 0 && j / temp > 0) {
                    dp[j / temp] = min(dp[j / temp], dp[j] + i);
                }

                if (j + temp < MAX) {
                    dp[j + temp] = min(dp[j + temp], dp[j] + i);
                }
                if (j - temp >= 0) {
                    dp[j - temp] = min(dp[j - temp], dp[j] + i);
                }
                if (temp - j >= 0) {
                    dp[temp - j] = min(dp[temp - j], dp[j] + i);
                }
            }
            temp *= 10;
            temp += N;
            if (temp > MAX) break;
        }
    }

    return dp[number] > 8 ? -1 : dp[number];
}
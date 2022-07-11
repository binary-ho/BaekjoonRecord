#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N, T, left_door, right_door, num;
int dp[21][21][21];
int main() {
    cin >> N >> left_door >> right_door;
    if(left_door > right_door) swap(left_door, right_door);
    cin >> T;
    for(int i = 0; i <= T; i++) {
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k <= N; k++) {
                dp[i][j][k] = 500;
            }
        }
    }
    dp[0][left_door][right_door] = 0;
    for(int i = 1; i <= T; i++) {
        cin >> num;
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if(dp[i-1][j][k] >= 500) continue;
                dp[i][j][num] = min(dp[i][j][num], dp[i-1][j][k] + abs(num - k));
                dp[i][num][k] = min(dp[i][num][k], dp[i-1][j][k] + abs(j - num));
            }
        }
    }
    int ans = 500;
    for(int j = 1; j <= N; j++) {
        for(int k = 1; k <= N; k++) {
            if(dp[T][j][k] > ans) continue;
            ans = dp[T][j][k] ;
        }
    }
    cout << ans;
}

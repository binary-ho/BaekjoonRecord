#include <string>
#include <vector>
#define DIV 1000000007
using namespace std;

long long dp[102][102];
int solution(int m, int n, vector<vector<int>> puddles) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 1;
        }
    }
    
    for (vector<int> vec : puddles) {
        int y = vec[1];
        int x = vec[0];
        
        if (y == 1) {
            for (int i = x; i <= m; i++) {
                dp[1][i] = 0;
            }
        }
        
        if (x == 1) {
            for (int i = y; i <= n; i++) {
                dp[i][1] = 0;
            }
        }
        
        dp[y][x] = 0;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (dp[i][j] == 0) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= DIV;
        }
    }
    
    return dp[n][m];
}
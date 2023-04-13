#include <string>
#include <vector>

using namespace std;

// N까지 가는 길 중 가장 큰?
// i랑 i + 1 갈 수 있다.
int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int ans = 0;
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            dp[i][j] = dp[i - 1][j];
            
            if (j != 0 && dp[i - 1][j - 1] > dp[i -1][j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            dp[i][j] += triangle[i][j];
            
            if (ans < dp[i][j]) {
                ans = dp[i][j];
            }
        }
    }
    
    return ans;
}
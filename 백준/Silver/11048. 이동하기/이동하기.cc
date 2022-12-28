#include <iostream>
using namespace std;
int N, M, maze[1001][1001], dp[1001][1001];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> maze[i][j];
    dp[0][0] = maze[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int y = i + dy[k], x = j + dx[k];
                if (0 > y || y >= N || 0 > x || x >= M) continue;
                dp[y][x] = max(dp[y][x], dp[i][j] + maze[y][x]);
            }
        }
    }
    cout << dp[N-1][M-1];
}

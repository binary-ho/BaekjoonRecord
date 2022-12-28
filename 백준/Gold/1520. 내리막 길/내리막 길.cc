#include <iostream>
using namespace std;
int M, N, map[501][501], ans;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
bool check[501][501];
int path[501][501];

int dfs(int y, int x) {
    if (path[y][x] != -1) return path[y][x];
    path[y][x] = 0;
    
    for (int i = 0; i < 4; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (0 > yy || yy >= M || 0 > xx || xx >= N) continue;
        if (check[yy][xx]) continue;
        if (map[yy][xx] >= map[y][x]) continue;
        check[yy][xx] = true;
        path[y][x] += dfs(yy, xx);
        check[yy][xx] = false;
    }
    return path[y][x];
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            path[i][j] = -1;
        }
    }
    path[M - 1][N - 1] = 1;
    printf("%d", dfs(0, 0));
}

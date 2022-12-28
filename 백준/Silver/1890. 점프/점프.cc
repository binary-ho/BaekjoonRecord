#include <iostream>
using namespace std;
int N, map[101][101];
long long path[101][101];
int dy[] = {0,1};
int dx[] = {1,0};
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];
    path[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 2; k++) {
                if (i == N - 1 && j == N - 1) {
                    cout << path[N - 1][N - 1];
                    return 0;
                }
                if (path[i][j] == 0) continue;

                int y = i + dy[k] * map[i][j], x = j + dx[k] * map[i][j];
                if (0 > y || y >= N || 0 > x || x >= N) continue;
                path[y][x] += path[i][j];
            }
        }
    }
}

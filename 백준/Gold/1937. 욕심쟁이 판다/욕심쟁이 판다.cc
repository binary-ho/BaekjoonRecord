#include <iostream>
#include <vector>

using namespace std;

int N, forest[501][501], panda[501][501], ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0 , 0};

int eatBoo(int yNow, int xNow) {
    if (panda[yNow][xNow] != 0) return panda[yNow][xNow];

    int eatCnt = 0;

    for (int i = 0; i < 4; i++) {
        int nextY = yNow + dy[i]; int nextX = xNow + dx[i];
        if (0 > nextY || nextY >= N || 0 > nextX || nextX >= N) continue;
        if (forest[yNow][xNow] >= forest[nextY][nextX]) continue;
        eatCnt = max(eatCnt, eatBoo(nextY, nextX));
    }
    panda[yNow][xNow] = eatCnt + 1;
    if (ans < panda[yNow][xNow]) ans = panda[yNow][xNow];
    return panda[yNow][xNow];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> forest[i][j];
    ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (panda[i][j] != 0) continue;
            eatBoo(i, j);
        }
    }
    cout << ans << '\n';
}

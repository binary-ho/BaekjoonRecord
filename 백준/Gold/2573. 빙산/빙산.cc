#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int sea[301][301];
int phaseCheck[301][301];

int to(int y, int x) {
    return y * M + x;
}

pair<int, int> to(int yx) {
    return {yx / M, yx % M};
}

// 만만은 36만 Byte
int main() {

    // 두 조각이 났냐??
    // 이게참 궁금해
    // 페이즈를 나누자
    // 수행 이후 몇 개가 남아 있어야 하고??
    // 실제론 몇 개였는지 세자

    int startY, startX, wholeIceCount = 0;
    cin >> N >> M;
    for (int i  = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sea[i][j];
            // 1이 아니다 -> 체크
            if (sea[i][j] != 0) {
                startY = i; startX = j;
                wholeIceCount++;
            }
        }
    }

    // 같은 페이즈면 못감
    int phase = 1;
    int currentIceCount, meltCount;
    int yNow, xNow, newY, newX, zeroCount;
    queue<int> que;
    while (1) {
        currentIceCount = meltCount = 0;
        que.push(to(startY, startX));
        phaseCheck[startY][startX] = phase;

        while (!que.empty()) {
            pair<int, int> pair = to(que.front());
            yNow = pair.first;
            xNow = pair.second;
            que.pop();

            currentIceCount++;
            zeroCount = 0;
            for (int i = 0; i < 4; i++) {
                newY = yNow + dy[i];
                newX = xNow + dx[i];

                // 밖
                if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;

                // 페이즈
                if (phaseCheck[newY][newX] >= phase) continue;

                // 제로
                if (sea[newY][newX] <= 0) {
                    zeroCount++;
                    continue;
                }

                que.push(to(newY, newX));
                phaseCheck[newY][newX] = phase;
            }

            // 후처리
            sea[yNow][xNow] -= zeroCount;
            if (sea[yNow][xNow] <= 0) {
                meltCount++;
                sea[yNow][xNow] = 0;
            } else {
                startY = yNow;
                startX = xNow;
            }
        }

        if (wholeIceCount > currentIceCount) {
            cout << phase - 1;
            return 0;
        }

        wholeIceCount -= meltCount;
        if (wholeIceCount == 0) {
            cout << 0;
            return 0;
        }

        phase++;
    }
}

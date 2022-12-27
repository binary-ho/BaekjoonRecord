#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int R, C, N, height;
bool mineral[101][101];
int check[101][101];
// 아래가 맨 끝..
// 좌우 상하 순서..
int checkCnt;
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
vector<pair<int, int>> cluster;
map<int, int> bottomPoint;

bool getCluster(int r, int c) {
    if (0 > r || r >= R || 0 > c || c >= C) return true;
    if (!mineral[r][c] || check[r][c] == checkCnt) return true;

    pair<int, int> axisNow;
    queue<pair<int, int>> que;
    check[r][c] = checkCnt;
    que.push({r, c});
    cluster.emplace_back(r, c);
    if (bottomPoint[c] < r) bottomPoint[c] = r;

    while (!que.empty()) {
        axisNow = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nextR = axisNow.first + dy[i];
            int nextC = axisNow.second + dx[i];
            if (0 > nextR || nextR >= R || 0 > nextC || nextC >= C) continue;
            if (!mineral[nextR][nextC] || check[nextR][nextC] == checkCnt) continue;
            if (nextR == R - 1) return true;
            check[nextR][nextC] = checkCnt;
            que.push({nextR, nextC});
            cluster.emplace_back(nextR, nextC);
            if (bottomPoint[nextC] < nextR) bottomPoint[nextC] = nextR;
        }
    }
    return false;
}


int main() {

    char input;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> input;
            if (input == '.') continue;
            mineral[i][j] = true;
        }
    }

    // 짝수일 때 왼쪽에서 던진다.
    checkCnt = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> height;
        height = R - height;
        int j;
        if (i%2 == 0) {
            for (j = 0; j < C; j++) {
                if (mineral[height][j]) break;
            }
        } else {
            for (j = C - 1; j >= 0; j--) {
                if (mineral[height][j]) break;
            }
        }
        mineral[height][j] = false;

        for (int k = 0; k < 4; k++) {
            cluster.clear();
            bottomPoint = {};
            checkCnt++;
            if (getCluster(height + dy[k], j + dx[k])) continue;


            // 단절되었다. 이제 만난 놈들을 전부 내려줘야한다.
            std::sort(cluster.begin(), cluster.end(), greater<>());
//            for (auto p : cluster) {
//                cout << p.first << " " << p.second << '\n';
//            }
            int moveCnt = 100, temp;
            for (auto axis : bottomPoint) {
                temp = axis.second;
                while (temp < R - 1 && !mineral[temp + 1][axis.first]) temp++;
                if (moveCnt > temp - axis.second) moveCnt = temp - axis.second;
//                cout << axis.second << " " << axis.first << " " << temp - axis.second << '\n';
            }

            if (moveCnt == 0) continue;
            for (auto axis : cluster) {
                //cout << axis.first << " " << axis.second << '\n';
                swap(mineral[axis.first][axis.second], mineral[axis.first + moveCnt][axis.second]);
                swap(check[axis.first][axis.second], check[axis.first + moveCnt][axis.second]);
            }
            break;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!mineral[i][j]) cout << '.';
            else cout << 'x';
        }
        cout << '\n';
    }
}

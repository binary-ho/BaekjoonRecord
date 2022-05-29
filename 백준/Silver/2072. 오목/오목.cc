#include <iostream>
#include <cstring>

using namespace std;
// 상하 좌우 오른쪽-위 왼쪽-위
int board[20][20], N;
// 0 2 4 6
int dy[] = {1, -1, 0,0, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};

bool check(int y, int x, int type) {
    int cnt = 0;
    int y_now = y, x_now = x;
    while(y_now >= 1 && y_now <= 19 && x_now >= 1 && x_now <= 19 && board[y_now][x_now] == board[y][x]) {
        cnt++;
        y_now += dy[type];
        x_now += dx[type];
    }
    y_now = y, x_now = x;
    while(y_now >= 1 && y_now <= 19 && x_now >= 1 && x_now <= 19 && board[y_now][x_now] == board[y][x]) {
        cnt++;
        y_now += dy[type + 1];
        x_now += dx[type + 1];
    }
    cnt--;
    if(cnt == 5) {
        return true;
    } else {
        return false;
    }
}



int main() {
    /*
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    */
    int y, x;
    cin >> N;
    memset(board, -1, sizeof(board));
    // 홀수 흑, 짝수 백
    for(int i = 0; i < N; i++) {
        cin >> y >> x;
        board[y][x] = i & 1;
        // 0 2 4 6
        for(int j = 0; j <= 6; j+=2) {
            if(!check(y, x, j)) continue;
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << -1;
}
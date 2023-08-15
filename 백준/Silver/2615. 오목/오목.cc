#include <iostream>

using namespace std;

int board[20][20];

// 위아래 / 양옆 / 왼위오아 / 오위왼아
// 왼쪽 + 위로 가는 방향으로 짜야 편할듯
int dy[] = {0, -1, 1, -1};
int dx[] = {-1, -1, -1, 0};

bool isIn(int y, int x) {
    return y >= 0 && y < 19 && x >= 0 && x < 19;
}

int isWin(int y, int x, int color) {
    int newY;
    int newX;

    for (int i = 0; i < 4; i++) {
        int count = 1;
        newY = y;
        newX = x;

        while (isIn(newY + dy[i], newX + dx[i]) && board[newY + dy[i]][newX + dx[i]] == color) {
            count++;
            newY += dy[i];
            newX += dx[i];
        }

        newY = y;
        newX = x;

        while (isIn(newY - dy[i], newX - dx[i]) && board[newY - dy[i]][newX - dx[i]] == color) {
            count++;
            newY -= dy[i];
            newX -= dx[i];
        }

        if (count == 5) {
            newY = y;
            newX = x;

            while (isIn(newY + dy[i], newX + dx[i]) && board[newY + dy[i]][newX + dx[i]] == color) {
                newY += dy[i];
                newX += dx[i];
            }
            return newY * 19 + newX;
        }
    }

    return -1;
}

int main() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] == 0) continue;
            int result = isWin(i, j, board[i][j]);
            if (result == -1) continue;
            cout << board[i][j] << '\n' << result / 19 + 1 << " " << result % 19 + 1;
            return 0;
        }
    }

    cout << "0";
}

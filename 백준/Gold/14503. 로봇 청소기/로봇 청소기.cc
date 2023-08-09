#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

// 0 3 2 1
// 4 - dir / 4
int direction, count = 0;
// 반시계로 북 서 남 동
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int room[51][51];
#define CLEAN 2
#define NOT_CLEAN 0
#define WALL 1

void go1(int r, int c);
void go2(int r, int c);
void go3(int r, int c);

void go1(int r, int c) {
    if (room[r][c] == NOT_CLEAN) {
        room[r][c] = CLEAN;
        count++;
    }

    // 4방 조사
    bool isCleanNear = true;
    int newR, newC;
    for (int i = 0; i < 4; i++) {
        newR = r + dy[i];
        newC = c + dx[i];
        if (newR < 0 || newR >= N || newC < 0 || newC >= M) continue;
        if (room[newR][newC] == WALL || room[newR][newC] == CLEAN) continue;
        // 청소되지 않은 칸이 있음
        isCleanNear = false;
    }

    if (isCleanNear) {
        go2(r, c);
    } else {
        go3(r, c);
    }
}

void go2(int r, int c) {
    int newR, newC;
    newR = r - dy[direction];
    newC = c - dx[direction];

    // 후진 가능
    if (newR >= 0 && newR < N && newC >= 0 && newC < M && room[newR][newC] != WALL) {
        go1(newR, newC);
    }
}

void go3(int r, int c) {
    direction = (direction + 1) % 4;

    int newR, newC;
    newR = r + dy[direction];
    newC = c + dx[direction];

    // 앞쪽이 청소 가능하면 한칸 전진
    // 청소 가능하고 벽이 아니다
    //
    if (newR >= 0 && newR < N && newC >= 0 && newC < M && room[newR][newC] == NOT_CLEAN) {
        go1(newR, newC);
        return;
    }
    go1(r, c);
}

int main() {
    // r, c

    // 1.현재칸 청 X
    // 1.1 -> 청소
    //
    // 2.모두 청소
    // 2.1 방향유지 + 후진 + 1번
    // 2.2 후진 불가 -> 멈춤

    // 3. 청소 X칸
    // 3.1 반시계 90도
    // 3.2 바라보는 쪽 앞 청소 x 청소 -> go

    cin >> N >> M;
    int r, c;
    cin >> r >> c >> direction;
    direction = (4 - direction) % 4;

    // room 채우기
    for (int i = 0;  i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    go1(r, c);
    cout << count;
}



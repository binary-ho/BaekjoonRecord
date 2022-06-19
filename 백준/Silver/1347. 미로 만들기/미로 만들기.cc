#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, L, R, U, D, y, x;
// 한계점을 의미
bool map[102][102];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};


int main() {

    char cmd;
    int arrow = 0;
    y = x = R = L = U = D = 50;
    map[y][x] = true;
    cin >> N;
    while(N--) {
        cin >> cmd;
        if(cmd == 'R') {
            arrow++;
            continue;
        }
        if(cmd == 'L') {
            arrow += 3;
            continue;
        }
        y += dy[arrow&3]; x += dx[arrow&3];
        if(!map[y][x]) {
            if(y > D) D = y;
            if(y < U) U = y;
            if(x > R) R = x;
            if(x < L) L = x;
            map[y][x] = true;
        }
    }

    for(int i = U; i <= D; i++) {
        for(int j = L; j <= R; j++) {
            if(map[i][j]) {
                cout << '.';
                continue;
            }
            cout << '#';
        }
        cout << '\n';
    }
}
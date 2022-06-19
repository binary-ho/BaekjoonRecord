#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
int N, M, A, B, arrow[101];
int map[101][101];
pair<int, int> robot[101];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};


int main() {
    char cmd;
    int y, x, num, cnt;
    cin >> A >> B >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> x >> y >> cmd;
        map[B-y+1][x] = i;
        robot[i] = {B-y+1, x};
        if(cmd == 'W') arrow[i] = 1;
        else if(cmd == 'N') arrow[i] = 2;
        else if(cmd == 'E') arrow[i] = 3;
    }
    while(M--) {
        cin >> num >> cmd >> cnt;
        if(cmd == 'R') {
            arrow[num] += cnt;
            continue;
        }
        if(cmd == 'L') {
            arrow[num] += 3*cnt;
            continue;
        }
        tie(y, x) = robot[num];
        while(1<= y && y <= B && 1 <= x && x <= A && cnt--) {
            map[y][x] = 0;
            y += dy[arrow[num]&3]; x += dx[arrow[num]&3];
            if(1<= y && y <= B && 1 <= x && x <= A) {
                if(map[y][x] != 0 && map[y][x] != num) {
                    cout << "Robot " << num << " crashes into robot " << map[y][x];
                    return 0;
                }
                map[y][x] = num; 
            }
        }
        if(cnt >= 0) {
            cout << "Robot " << num << " crashes into the wall";
            return 0;
        }
        robot[num] = {y,x};
    }
    cout << "OK";
}
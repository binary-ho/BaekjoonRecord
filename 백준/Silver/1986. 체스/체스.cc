#include <iostream>
#include <vector>

using namespace std;
// 0이 안전한 곳이고 1이 못 가고, 2가 뭔가 놓여 있음
int N, M, num, y, x, ans;
vector<pair<int, int>> queen;
vector<pair<int, int>> knight;
int map[1001][1001];
int dy[] = {0, 0, 1,-1, 1, 1, -1,-1};
int dx[] = {1, -1, 0, 0, -1, 1, -1,1};
// 4 5 6 7

int main() {
    cin >> N >> M;
    ans = N * M;
    cin >> num;
    ans -= num;
    for(int i = 0; i < num; i++) {
        cin >> y >> x;
        queen.emplace_back(y, x);
        map[y][x] = 2;
    }
    cin >> num;
    ans -= num;
    for(int i = 0; i < num; i++) {
        cin >> y >> x;
        knight.emplace_back(y, x);
        map[y][x] = 2;
    }
    cin >> num;
    ans -= num;
    for(int i = 0; i < num; i++) {
        cin >> y >> x;
        map[y][x] = 2;
    }
    for(int i = 0; i < queen.size(); i++) {
        map[queen[i].first][queen[i].second] = 1;
        for(int j = 0; j < 8; j++) {
            y = queen[i].first; x= queen[i].second;
            while(y > 0 && y <= N && x > 0 && x <= M && map[y][x] != 2) {
                if(map[y][x] == 0) ans--;
                map[y][x] = 1;
                y += dy[j]; x += dx[j];
            }
        }
        map[queen[i].first][queen[i].second] = 2;
    }

    for(int i = 0; i < knight.size(); i++) {
        for(int j = 4; j < 8; j++) {
            y = knight[i].first; x= knight[i].second;
            y += 2*dy[j]; x += dx[j];
            if(y > 0 && y <= N && x > 0 && x <= M && map[y][x] == 0) {
                map[y][x] = 1;
                ans--;
            }
            y = knight[i].first; x= knight[i].second;
            y += dy[j]; x += 2*dx[j];
            if(y > 0 && y <= N && x > 0 && x <= M && map[y][x] == 0) {
                map[y][x] = 1;
                ans--;
            }
        }
    }
    cout << ans;
}
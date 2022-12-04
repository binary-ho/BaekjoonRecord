#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int R, C;
char maze[1001][1001];
bool maze_check[1001][1001];
bool fire_check[1001][1001];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int main(int argc, char *argv[]) {
    cin >> R >> C;
    int r, c;
    vector<pair<int, int>> fire;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'J') {
                r = i;
                c = j;
            }
            if (maze[i][j] == 'F') {
                fire.emplace_back(i, j);
            }
        }

    queue<pair<pair<int, int>, pair<bool, int>>> que;
    que.push({{r, c}, {true, 0}});
    maze_check[r][c] = true;
    for (auto f : fire) {
        que.push({f, {false, 0}});
        fire_check[f.first][f.second] = true;
    }
    bool isJihun;
    int r_now, c_now, next_r, next_c, cost_now, best = 987654321;
    while(!que.empty()) {
        auto node_now = que.front();
        isJihun = node_now.second.first;
        r_now = node_now.first.first;
        c_now = node_now.first.second;
        cost_now = node_now.second.second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            next_r = r_now + dr[i]; next_c = c_now + dc[i];
            if (R <= next_r || next_r < 0 || C <= next_c || next_c < 0) {
                if (isJihun && !fire_check[r_now][c_now] && best > cost_now + 1) best = cost_now + 1;
                continue;
            }
            if (maze[next_r][next_c] == '#' || fire_check[next_r][next_c]) continue;
            if (isJihun && maze_check[next_r][next_c]) continue;
            que.push({{next_r, next_c}, {isJihun, cost_now + 1}});
            if (isJihun) maze_check[next_r][next_c] = true;
            else fire_check[next_r][next_c] = true;
        }
    }
    if (best == 987654321) cout << "IMPOSSIBLE";
    else cout << best;
}

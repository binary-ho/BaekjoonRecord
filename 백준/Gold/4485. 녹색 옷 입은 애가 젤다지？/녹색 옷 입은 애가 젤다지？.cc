#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>

#define INF 200000
using namespace std;
int N;
int map[126][126], dy[] = {0,0,-1,1}, dx[] = {1, -1,0,0};
int dist[126][126];
int y_now, x_now, new_y, new_x, cost_now, axis;

int T;
priority_queue<pair<int, int>> que;
void dijkstra() {
    dist[0][0] = map[0][0];
    que.push({-map[0][0], 0});
    while(!que.empty()) {
        tie(cost_now, axis) = que.top();
        que.pop();
        cost_now *= -1;
        y_now = axis/N;
        x_now = axis%N;
        if(dist[y_now][x_now] < cost_now) continue;
        if(y_now == N - 1 && x_now == N - 1) break;
        for(int i = 0; i < 4; i++) {
            new_y = y_now + dy[i]; new_x = x_now + dx[i];
            if(0 > new_y || new_y >= N || 0 > new_x || new_x >= N) continue;
            if(cost_now + map[new_y][new_x] >= dist[new_y][new_x]) continue;
            dist[new_y][new_x] = cost_now + map[new_y][new_x];
            que.push({-(dist[new_y][new_x]), new_y*N + new_x});
        }
        //cout << "1";
    }

    cout << "Problem " << T << ": " << dist[N-1][N-1] << '\n';
    que = {};

    return;
}

int main() {
    T = 0;
    while(1) {
        T++;
        cin >> N;
        if(N==0) return 0;
        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) { cin >> map[i][j]; dist[i][j] = INF; }
        dijkstra();
    }
}
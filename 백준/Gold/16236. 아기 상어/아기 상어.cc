#include<iostream>
#include <string>
//#include <stack>
#include <vector>
//#include <algorithm>
#include <queue>
#include<cstring>
using namespace std;

int N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<pair<int, int>> fish_tank;

int size_now = 2;
int arr[21][21];
int dist[21][21];
bool check[21][21];

void bfs(int y, int x) {
    memset(check, false, sizeof(check));
    memset(dist, 0, sizeof(dist));
    
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    dist[y][x] = 0;
    check[y][x] = true;
    while (!que.empty()) {
        int y_now = que.front().first; int x_now = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int y_new = y_now + dy[i]; int x_new = x_now + dx[i];
            if (0 < y_new && y_new <= N && 0 < x_new && x_new <= N) {
                if (check[y_new][x_new] == false && arr[y_new][x_new] <= size_now) {
                    que.push(make_pair(y_new, x_new));
                    dist[y_new][x_new] = dist[y_now][x_now] + 1;
                    check[y_new][x_new] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int input, baby_x, baby_y;
    cin >> N;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> input;
            arr[y][x] = input;
            if (input != 9 && input != 0) {
                fish_tank.push_back(make_pair(y, x));
            }
            else if (input == 9) {
                baby_x = x;
                baby_y = y;
            }
        }
    }
    if (fish_tank.empty()) {
        cout << 0;
        return 0;
    }

    int eat = 0;
    int move_dist = 0;
    
    arr[baby_y][baby_x] = 0;
    int tank_size = fish_tank.size();
    while (tank_size--) {

        bfs(baby_y, baby_x);

        /*for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cout << dist[i][j];
            }
            cout << '\n';
        }*/
        int target_y = 22; int target_x = 22;
        int dist_min = 1000;
        for (int i = 0; i < fish_tank.size(); i++) {
            int fish_y = fish_tank[i].first; int fish_x = fish_tank[i].second;
            if (arr[fish_y][fish_x] != 0 && arr[fish_y][fish_x] < size_now
                && dist[fish_y][fish_x] != 0 && dist[fish_y][fish_x] < dist_min) {
                target_y = fish_y; target_x = fish_x;
                dist_min = dist[fish_y][fish_x];
            }
            else if (arr[fish_y][fish_x] != 0 && arr[fish_y][fish_x] < size_now
                && dist[fish_y][fish_x] != 0 && dist[fish_y][fish_x] == dist_min && target_y > fish_y) {
                target_y = fish_y; target_x = fish_x;
                dist_min = dist[fish_y][fish_x];
            }
            else if (arr[fish_y][fish_x] != 0 && arr[fish_y][fish_x] < size_now
                && dist[fish_y][fish_x] != 0 && dist[fish_y][fish_x] == dist_min && target_y == fish_y && target_x > fish_x) {
                target_y = fish_y; target_x = fish_x;
                dist_min = dist[fish_y][fish_x];
            }

        }
        if (dist_min == 1000) {
            break;
        }
        
        //cout << "추적 물고기: " << "(" << target_x<< "," << target_y<< ")좌표의 크기 " << arr[target_y][target_x] 
        //    << "짜리 물고기. 이동거리: " << (abs(baby_y - target_y) + abs(baby_x - target_x)) << ". 크기 : "<<size_now<<'\n';
        move_dist += dist_min;
        arr[target_y][target_x] = 0;
        baby_y = target_y; baby_x = target_x;
        eat++;
        if (size_now == eat) {
            size_now++;
            eat = 0;
        }
    }
    cout << move_dist;
}
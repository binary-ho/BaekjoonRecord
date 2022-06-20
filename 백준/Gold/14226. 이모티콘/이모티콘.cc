#include<iostream>
#include <string>
//#include <stack>
#include <vector>
//#include <algorithm>
#include <queue>
#include<cstring>
using namespace std;

int S;
int dist[1001][1001];
bool check[1001][1001];
void bfs(int input) {
    queue<pair<int, int>> que;
    que.push(make_pair(input, 0));
    //check[input][0] = true;
    dist[input][0] = 0;
    while (!que.empty()) {
        int num_now = que.front().first;
        int copy_now = que.front().second;
        que.pop();
        if (dist[num_now][num_now] == -1) {
            que.push(make_pair(num_now, num_now));
            dist[num_now][num_now] = dist[num_now][copy_now] + 1;
        }
        if ((num_now + copy_now) <= 1000 && dist[num_now + copy_now][copy_now] == -1) {
            que.push(make_pair(num_now + copy_now, copy_now));
            dist[num_now + copy_now][copy_now] = dist[num_now][copy_now] + 1;
        }
        if (num_now > 1 && dist[num_now - 1][copy_now] == -1) {
            que.push(make_pair(num_now - 1, copy_now));
            dist[num_now - 1][copy_now] = dist[num_now][copy_now] + 1;
        }
    }
}

/*void pre_order(int node_now) {
    cout << (char)node_now;
    if (child[node_now][0] != -1) {pre_order(child[node_now][0]);}
    if (child[node_now][1] != -1) {pre_order(child[node_now][1]);}
}
void in_order(int node_now, int level_y_now) {
    if (child[node_now][0] != 0) {in_order(child[node_now][0], level_y_now + 1);}
    vec[level_y_now].push_back(level_x);
    if (level_y < level_y_now) { level_y = level_y_now; }
    level_x++;
    if (child[node_now][1] != 0) {in_order(child[node_now][1], level_y_now + 1);}
}
void post_order(int node_now) {
    if (child[node_now][0] != -1) { post_order(child[node_now][0]); }
    if (child[node_now][1] != -1) { post_order(child[node_now][1]); }
    
}*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    memset(dist, -1, sizeof(dist));
    bfs(1);
    int min_cost = 10000;
    for (int i = 0; i <= 1000; i++) {
        if (dist[S][i] != -1) {
            min_cost = min(min_cost, dist[S][i]);
        }
    }
    cout << min_cost;
}
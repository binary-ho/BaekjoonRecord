#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 50000001

using namespace std;
int n, m, t, s, g, h, src, dest, cost, T, node_now, dist_now, next_node;
vector<pair<int, int>> vec[2001];
priority_queue<pair<int, int>> que;
int dist[3][2001];
void dijkstra(int start, int dist_num) {
    dist[dist_num][start] = 0;
    que.push({0, start});
    while(!que.empty()) {
        node_now = que.top().second;
        dist_now = -que.top().first;
        que.pop();
        if(dist[dist_num][node_now] < dist_now) continue;
        for(int i = 0; i < vec[node_now].size(); i++) {
            next_node = vec[node_now][i].first;
            cost = vec[node_now][i].second;
            if(dist[dist_num][next_node] <= dist_now + cost) continue;
            dist[dist_num][next_node] = dist_now + cost;
            que.push({-dist[dist_num][next_node], next_node});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<int> ans;

    cin >> T;
    while(T--) {

        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for(int i = 0; i <= n; i++) {
            vec[i] = {};
            dist[0][i] = dist[1][i] = dist[2][i] = INF;
        }
        for(int i = 0; i < m; i++) {
            cin >> src >> dest >> cost;
            vec[src].emplace_back(dest, cost);
            vec[dest].emplace_back(src, cost);
        }
        vector<int> dest_vec(t, 0);
        for(int i = 0; i < t; i++) {
            cin >> dest_vec[i];
        }

        dijkstra(s, 0);
        dijkstra(g, 1);
        dijkstra(h, 2);


        ans.clear();
        int g_to_h = dist[1][h];
        for(int node : dest_vec) { 
            if(dist[0][g] + g_to_h + dist[2][node] == dist[0][node]) ans.emplace_back(node);
            else if(dist[0][h] + g_to_h + dist[1][node] == dist[0][node]) ans.emplace_back(node);
        }
        sort(ans.begin(), ans.end());
        for(int num : ans) {
            cout << num << " ";
        }
        cout << '\n';
    }
}

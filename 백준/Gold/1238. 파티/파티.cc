#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M, X, src, dest, cost;
    cin >> N >> M >> X;
    vector<pair<int, int>> vec[N+1];
    for(int i = 0; i < M; i++) {
        cin >> src >> dest >> cost;
        vec[src].emplace_back(dest, cost);
    }
    int dist[N+1][N+1];
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            dist[i][j] = 987654321;
        }
    }

    priority_queue<pair<int, int>> que;
    for(int n = 1; n <= N; n++) {
        dist[n][n] = 0;
        que.push({-dist[n][n], n});
        while (!que.empty()) {
            int dist_now = -que.top().first;
            int node_now = que.top().second;
            que.pop();
            if(dist[n][node_now] < dist_now) continue;
            for (int i = 0; i < vec[node_now].size(); i++) {
                int next_node = vec[node_now][i].first;
                int cost_now = vec[node_now][i].second;
                if (dist[n][next_node] < dist_now + cost_now) continue;
                dist[n][next_node] = dist_now + cost_now;
               
                que.push({-dist[n][next_node], next_node});
            }
        }
    }
    int ans = 0, temp;

    for(int i = 1; i <= N; i ++) {
        temp = dist[i][X] + dist[X][i];
        if(ans < temp) ans = temp;
    }
    cout << ans;
}

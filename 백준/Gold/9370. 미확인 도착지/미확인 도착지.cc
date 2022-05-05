#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

#define INF 50000001

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    priority_queue<pair<int, int>> que;
    int dist[2001], dist2[2001], dist3[2001];
    vector<pair<int, int>> vec[2001];
    vector<int> ans;
    int n, m, t, s, g, h, src, dest, cost, T, node_now, dist_now, next_node, must_pass;
    cin >> T;
    while(T--) {

        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for(int i = 0; i <= n; i++) {
            vec[i] = {};
            dist[i] = dist2[i] = dist3[i] = INF;
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

        dist[s] = 0;
        que.push({0, s});
        while(!que.empty()) {
            node_now = que.top().second;
            dist_now = -que.top().first;
            que.pop();
            if(dist[node_now] < dist_now) continue;
            for(int i = 0; i < vec[node_now].size(); i++) {
                next_node = vec[node_now][i].first;
                cost = vec[node_now][i].second;
                if(dist[next_node] <= dist_now + cost) continue;
                dist[next_node] = dist_now + cost;
                que.push({-dist[next_node], next_node});
            }
        }
        must_pass = g;
        dist2[must_pass] = 0;
        que.push({0, must_pass});
        while(!que.empty()) {
            node_now = que.top().second;
            dist_now = -que.top().first;
            que.pop();
            if(dist2[node_now] < dist_now) continue;
            for(int i = 0; i < vec[node_now].size(); i++) {
                next_node = vec[node_now][i].first;
                cost = vec[node_now][i].second;
                if(dist2[next_node] <= dist_now + cost) continue;
                dist2[next_node] = dist_now + cost;
                que.push({-dist2[next_node], next_node});
            }
        }
        must_pass = h;
        dist3[must_pass] = 0;
        que.push({0, must_pass});
        while(!que.empty()) {
            node_now = que.top().second;
            dist_now = -que.top().first;
            que.pop();
            if(dist3[node_now] < dist_now) continue;
            for(int i = 0; i < vec[node_now].size(); i++) {
                next_node = vec[node_now][i].first;
                cost = vec[node_now][i].second;
                if(dist3[next_node] <= dist_now + cost) continue;
                dist3[next_node] = dist_now + cost;
                que.push({-dist3[next_node], next_node});
            }
        }
        // dist2[후보] + dist[must_pass] != dist[후보] 면 탈릭
        int g_to_h = dist2[h];
        ans = {};
        for(int node : dest_vec) {
            if(dist[h] + g_to_h +  dist2[node] == dist[node]) ans.emplace_back(node);
            else if(dist[g] + g_to_h +  dist3[node] == dist[node]) ans.emplace_back(node);
        }
        sort(ans.begin(), ans.end());
        for(int num : ans) {
            cout << num << " ";
        }
        cout << '\n';
    }
}
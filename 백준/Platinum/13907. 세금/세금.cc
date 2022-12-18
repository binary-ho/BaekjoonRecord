#include <iostream>
#include <vector>
#include <queue>
#define INF 1987654321

using namespace std;

int N, M, K, S, D, a, b, w, p;
int dijkstra_dist[1001][1001];
vector<pair<int, int>> city[1001];

int main() {
    scanf("%d %d %d %d %d", &N, &M, &K, &S, &D);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &w);
        city[a].emplace_back(b, w);
        city[b].emplace_back(a, w);
    }

    for (int i = 0; i <= N; i++) for (int j = 0; j < N; j++) dijkstra_dist[i][j] = INF;
    pair<int, pair<int, int>> pair_now;
    priority_queue<pair<int, pair<int, int>>> p_que;
    p_que.push({0, {S, 0}});
    dijkstra_dist[S][0] = 0;

    int node_now, dist_now, cnt_now, next_node, cnt_next, next_dist;
    while (!p_que.empty()) {
        pair_now = p_que.top();
        node_now = pair_now.second.first;
        dist_now = -1 * pair_now.first;
        cnt_now = pair_now.second.second;
        p_que.pop();

        if (dijkstra_dist[node_now][cnt_now] < dist_now) continue;
        for (int i = 0; i < city[node_now].size(); i++) {
            next_node = city[node_now][i].first;
            if (dijkstra_dist[next_node][cnt_now + 1] <= dist_now + city[node_now][i].second) continue;
//            cout <<  node_now << " " << next_node << " " << dist_now + city[node_now][i].second << " " <<  cnt_now + 1<< '\n';
            dijkstra_dist[next_node][cnt_now + 1] = dist_now + city[node_now][i].second;
            p_que.push({-1 * (dijkstra_dist[next_node][cnt_now + 1]) ,{next_node, cnt_now + 1}});
        }
    }
    // 잡고 싶은건, 느리지만 더 적은 횟수인 것

    int ans = INF, bias = 0, stop, stop2, result;
    for (int cnt = 1; cnt <= N; cnt++) {
        result = dijkstra_dist[D][cnt];
        if (result == 0) continue;
        if (ans > result + bias * cnt) {
            ans = result + bias * cnt;
            stop = stop2 = cnt;
        }
    }
    printf("%lld\n", ans);

    for (int i = 0; i < K; i++) {
        ans = INF;
        scanf("%d", &p);
        bias += p;
        for (int cnt = stop; cnt > 0; cnt--) {
            int dist = dijkstra_dist[D][cnt];
            if (ans > dist + cnt * bias) {
                ans = dist + cnt * bias;
                stop2 = cnt;
            }
        }

        stop = stop2;
        printf("%lld\n", ans);
    }
}

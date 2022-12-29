#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
// src -> dest, cost
vector<pair<int, int>> bus[501];
long long dist[501];
int main() {
    int N, M, A, B, C;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        bus[A].emplace_back(B, C);
    }

    for (int i = 1; i <= N; i++ ) dist[i] = INF;
    dist[1] = 0;
    int nextNode, cost;
    bool relaxation;
    for (int i = 0; i < N; i++) {
        relaxation = false;
        for (int node = 1; node <= N; node++) {
            for (int j = 0; j < bus[node].size(); j++) {
                nextNode = bus[node][j].first; cost = bus[node][j].second;
                if (dist[nextNode] <= dist[node] + cost) continue;
                dist[nextNode] = dist[node] + cost;
                if (dist[nextNode] < INF - 10000000) relaxation = true;
            }
        }
        if (!relaxation) break;
    }
    if (relaxation) cout << -1;
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] < INF - 100000000) cout << dist[i] << '\n';
            else cout << -1 << '\n';
        }
    }
}

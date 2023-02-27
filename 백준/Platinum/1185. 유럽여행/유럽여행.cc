#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;
// 가성비, i, j, 비용, 시간
// 노드 간선 코스트, 간선코스트, 노드1, 2
#define tp tuple<int, int, int, int>

const int MAX_V = 10001;

int N, P, ans = 0;
int node_cost[MAX_V];
// 가성비, i, j, 비용, 시간
vector<tp> edges;


struct disjoint_set {
	vector<int> parent, rank;
	disjoint_set(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (u == parent[u])  return u; 
		return parent[u] = find(parent[u]); 
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		// 이미 같은 트리에 있는 경우 예외
		if (u == v) { return; }
		if (rank[u] > rank[v]) { swap(u, v); }
		parent[u] = v;
		if (rank[u] == rank[v]) { ++rank[v]; }
	}
};

// 결과로 bfs가 가능한 무언가가 나와야함
// 혹은 dfs. 인접 리스트 vector 하나, 그리고 시작점 결정.
// 모든 노드에 대해서 돌라다가는 터져
void kruskal() {
	disjoint_set sets(N+1);
	bool start = false;
	int total_cost, cost, u, v, be, dest;
	for (int i = 0; i < edges.size(); i++) {
		tie(total_cost, cost, u, v) = edges[i];
		if (sets.find(u) == sets.find(v)) { continue; }
		sets.merge(u, v);
		ans += total_cost;
	}
	//dest = v;
	//ans += line[u][v];
	//cout << be << ' ' << dest << '\n';
	// 방문한 노드들 중에서 서로 이어지지 않은 녀석들을 전부 찾아. 그 중에서 가장 저렴한놈.
	
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int cost, u, v, s, s_cost = 1001;
	cin >> N >> P;
	for (int i = 1; i <= N; i++) {
		cin >> cost;
		node_cost[i] = cost;
        if(s_cost > cost){
            s = i;
            s_cost = cost;
        }
	}
    ans += s_cost;
	for (int i = 0; i < P; i++) {
		cin >> u >> v >> cost;
		int n_cost = node_cost[u] + node_cost[v];
		edges.push_back({ 2*cost + n_cost, cost, u, v });
		edges.push_back({ 2*cost + n_cost, cost, v, u });
	}
	sort(edges.begin(), edges.end());
	kruskal();
	cout << ans;
}
// c/t가 최대가 되도록 만들어봐용
// '시간 당 이득'이 '최대'니까 반대로 정렬 근데, t랑 c도 데리
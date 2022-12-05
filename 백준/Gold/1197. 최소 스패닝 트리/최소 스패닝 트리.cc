#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

const int MAX_V = 10001;

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

int V;
vector<pair<int, int>> vec[MAX_V];

// 주어진 그래프에 대해, 최소 스패닝 트리에 포함된 간선의 목록을 selected에 저장하고
// 가중치 합을 반환한다.
int kruskal(vector<pair<int, int>>& selected) {
	int result = 0;
	selected.clear();

	vector<pair<int, pair<int, int>>> edges;
	for (int node_now = 1; node_now <= V; node_now++) {
		for (int i = 0; i < vec[node_now].size(); i++) {
			int next_node = vec[node_now][i].first; int cost = vec[node_now][i].second;
			edges.push_back({ cost, {node_now, next_node }});
			//cout << '1' << '\n';
		}
	}
	sort(edges.begin(), edges.end());

	disjoint_set sets(V+1);
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u, v;
		tie(u, v) = edges[i].second;
		if (sets.find(u) == sets.find(v)) { continue; }
		sets.merge(u, v);
		selected.push_back({ u, v });
		result += cost;
		//cout << '2' << '\n';
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int e, a, b, c;
	cin >> V >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vec[a].push_back({ b, c });
		//vec[b].push_back({ a, c });
	}
	vector<pair<int, int>> ans;
	cout << kruskal(ans);
}
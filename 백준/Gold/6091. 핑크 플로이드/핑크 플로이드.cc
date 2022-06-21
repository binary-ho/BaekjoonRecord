#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_V = 100001;

int N;
int arr[1025][1025];
vector<int> ans[1025];

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

vector<pair<int, pair<int, int>>> edges;

void kruskal() {
	disjoint_set sets(N+1);
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u, v;
		tie(u, v) = edges[i].second;
		if (sets.find(u) == sets.find(v)) { continue; }
		//result += sets.merge(u, v, cost);
		sets.merge(u, v);
		ans[u].push_back(v);
		ans[v].push_back(u);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int cost;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			cin >> cost;
			edges.push_back({ cost, {i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	kruskal();
	for (int i = 1; i <= N; i++) {
		sort(ans[i].begin(), ans[i].end());
		cout << ans[i].size() << ' ';
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ' '; 
		}
		cout << '\n';
	}
}
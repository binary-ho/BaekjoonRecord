#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

int N, K;
int cost[1001];
int cnt_edges[1001];
int ans[1001];
vector<int> vec[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--) {
		int a, b, c, w;
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> c;
			cost[i] = c;
		}
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			vec[a].push_back(b);
			cnt_edges[b]++;
		}
		cin >> w;
		queue<int> que;
		for (int i = 1; i <= N; i++) {
			if (cnt_edges[i] != 0) { continue; }
			que.push(i);
		}
		// phase개념이 필요 없을 수도 있음
		for (int i = 1; i <= N; i++) {
			int num_now = que.front();
			que.pop();
			if (num_now == w) { break; }
			for (int j = 0; j < vec[num_now].size(); j++) {
				int num_next = vec[num_now][j];
				cnt_edges[num_next]--;
				if (ans[num_next] < ans[num_now] + cost[num_now]) { ans[num_next] = ans[num_now] + cost[num_now]; }
				if (cnt_edges[num_next] != 0) { continue; }
				que.push(num_next);
			}
		}
		cout << ans[w] + cost[w] << '\n';
		for (int i = 0; i <= N; i++) {
			vec[i].clear();
		}
		memset(cost, 0, sizeof(cost));
		memset(cnt_edges, 0, sizeof(cnt_edges));
		memset(ans, 0, sizeof(ans));
	}
}

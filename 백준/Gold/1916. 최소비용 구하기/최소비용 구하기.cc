#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int N, M, city_start, city_dest;
int cost_max = 100000001;
// 도착지점, 코스트


int main() {
	cin >> N >> M;
	int from, to, cost;
	vector<pair<int, int>> vec[1001];
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		vec[from].push_back({ to, cost });
	}
	cin >> city_start >> city_dest;

	priority_queue<pair<int, int>> p_que;
	vector<int> dist(N + 1, cost_max);
	p_que.push({ 0, city_start });
	dist[city_start] = 0;
	while (!p_que.empty()) {
		int city_now = p_que.top().second;
		int cost_now = (-1) * p_que.top().first;
		p_que.pop();
		if (dist[city_now] < cost_now) { continue; }
		for (int i = 0; i < vec[city_now].size(); i++) {
			int next_city = vec[city_now][i].first;
			int cost_move = vec[city_now][i].second;
			if (dist[next_city] > cost_now + cost_move) {
				dist[next_city] = cost_now + cost_move;
				p_que.push({ (-1) * dist[next_city], next_city });
			}
		}
	}
	cout << dist[city_dest];
}

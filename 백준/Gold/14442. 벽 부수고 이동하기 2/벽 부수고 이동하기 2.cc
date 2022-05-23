#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cstring>
#include <stack>
//#include <bitset>

using namespace std;

int N, M, K;
int map[1001][1001];
bool check[1001][1001][10];
vector<pair<int, int>> vec;
int ans = 1000001;

// 오로지 0만 지나다닐 수 있게 해야할거 같아
int dy[] = {-1, 1, 0 ,0};
int dx[] = {0, 0, -1, 1};

void bfs() {
	queue<tuple<int,int, int, int>> que;
	que.push({ 1,1,0,1 });
	check[1][1][0] = true;
	while (!que.empty()) {
		int y_now, x_now, b_now, cnt_now;
		tie(y_now, x_now, b_now, cnt_now) = que.front();
		que.pop();
		if (y_now == N && x_now == M) {
			ans = cnt_now;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int new_y = y_now + dy[i]; int new_x = x_now + dx[i];
			if (1 > new_y || new_y > N || 1 > new_x || new_x > M) { continue; }
			if (map[new_y][new_x] == 0 && check[new_y][new_x][b_now] == false) {
				que.push({ new_y, new_x, b_now, cnt_now+1 });
				check[new_y][new_x][b_now] = true;
			}
			else if (map[new_y][new_x] == 1 && check[new_y][new_x][b_now+1] == false && b_now < K) {
				que.push({ new_y, new_x, b_now+1, cnt_now+1 });
				check[new_y][new_x][b_now+1] = true;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string input;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			if (input[j] == '0') {
				map[i+1][j+1] = 0;
				//zero.push_back({ i+1,j+1 });
			}
			else {
				map[i+1][j+1] = 1;
				//wall.push_back({ i+1, j+1 });
			}
		}
	}
	bfs();
	if (ans == 1000001) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}
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

//vector<pair<int, int>> wall;
//vector<pair<int, int>> zero;

int N, M, K;
int map[1001][1001];
bool check[1001][1001][10];
bool stop = false;

// y좌표, x좌표, 벽 부순 횟수, cnt
queue<tuple<int,int, int, int>> day;
queue<tuple<int, int, int, int>> night;
int ans = 2000002;

// 오로지 0만 지나다닐 수 있게 해야할거 같아
int dy[] = {-1, 1, 0 ,0,0};
int dx[] = { 0, 0, -1, 1,0};

// 밖에서 시작할 때부터 걍 day에 시작위치 넣어주고 시작하자.
// 생각해보니 낮에는 가만히 있을 필요가 없어
void bfs_day() {
	while (!day.empty()) {
		int y_now, x_now, b_now, cnt_now;
		tie(y_now, x_now, b_now, cnt_now) = day.front();
		day.pop();
		if (y_now == N && x_now == M) {
			ans = cnt_now;
			stop = true;
			return;
		}
		//if (cnt_now == 2000001) { continue; }
		for (int i = 0; i < 4; i++) {
			int new_y = y_now + dy[i]; int new_x = x_now + dx[i];
			if (1 > new_y || new_y > N || 1 > new_x || new_x > M) { continue; }
			if (map[new_y][new_x] == 0 && check[new_y][new_x][b_now] == false) {
				night.push({ new_y, new_x, b_now, cnt_now+1 });
				check[new_y][new_x][b_now] = true;
			}
			else if (map[new_y][new_x] == 1 && check[new_y][new_x][b_now+1] == false && b_now < K) {
				night.push({ new_y, new_x, b_now+1, cnt_now+1 });
				check[new_y][new_x][b_now+1] = true;
			}
		}
	}
}

void bfs_night() {
	while (!night.empty()) {
		int y_now, x_now, b_now, cnt_now;
		tie(y_now, x_now, b_now, cnt_now) = night.front();
		night.pop();

		if (y_now == N && x_now == M) {
			ans = cnt_now;
			stop = true;
			return;
		}
		//if (cnt_now == 2000001) { continue; }
		for (int i = 0; i < 4; i++) {
			int new_y = y_now + dy[i]; int new_x = x_now + dx[i];
			if (1 > new_y || new_y > N || 1 > new_x || new_x > M) { continue; }
			if (map[new_y][new_x] == 0 && check[new_y][new_x][b_now] == false){
				day.push({ new_y, new_x, b_now, cnt_now + 1 });
				check[new_y][new_x][b_now] = true;
			}
		}
        day.push({ y_now, x_now, b_now, cnt_now + 1 });
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
			}
			else {
				map[i+1][j+1] = 1;
			}
		}
	}
	day.push({ 1,1,0,1 });
	check[1][1][0] = true;
	while (1) {
		if (stop == true) { break; }
		else if (day.empty() && night.empty()) { break; }
		else if (!day.empty() && night.empty()) { bfs_day(); }
		else if (day.empty() && !night.empty()) { bfs_night(); }
	}
	if (stop == false) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}
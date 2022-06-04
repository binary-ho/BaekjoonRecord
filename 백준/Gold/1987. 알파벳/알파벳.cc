#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//#include <cstring>

using namespace std;

int R, C;
int ans = 0;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

int board[21][21];
bool check[91];
int dist[21][21];

void dfs(int y, int x, int cnt) {
	if (ans < cnt) { ans = cnt; }
	
	for (int i = 0; i < 4; i++) {
		int new_y = y + dy[i]; int new_x = x + dx[i];
		if (0 < new_y && new_y <= R && 0 < new_x && new_x <= C
			&& check[board[new_y][new_x]] == false) {
			check[board[new_y][new_x]] = true;
			dfs(new_y, new_x, cnt+1);
			check[board[new_y][new_x]] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> R >> C;
	
	for (int i = 1; i <= R; i++) {
		cin >> s;
		for (int j = 1; j <= C; j++) {
			board[i][j] = s[j - 1];
		}
	}
	

	check[board[1][1]] = true;
	dfs(1, 1, 1);
	check[board[1][1]] = false;
	cout << ans;

}
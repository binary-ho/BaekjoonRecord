#include <iostream>
#include <vector>
//#include <queue>
#include <algorithm>
//#include <cstring>
//#include <stack>
//#include <bitset>
using namespace std;

int N;
int map[20][20];
int ans = 401;


/*for (int j = 0; j < N; j++) {
	if (j == k) { continue; }
	int one = 0;
	for (int i = 0; i < N; i++) {
		if (m[i][j] == 1) { one++; }
	}
	int zero = N - one;
	if (one > zero) { cnt += zero; }
	else { cnt += zero; }
}*/


/*void game3(int k, int m[20][20]) {
	game1(k + 1, m);
	game3(k + 1, m);
}*/

void game2(int m[20][20]) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int one = 0;
		for (int j = 0; j < N; j++) {
			if (m[i][j] == 1) { one++; }
		}
		int zero = N - one;
		if (one > zero) { cnt += zero; }
		else { cnt += one; }
	}
	if (ans > cnt) { ans = cnt; }
}
void game1(int k, int m[20][20]) {
	// 일단 눌러버렸습니다~~
	if (k == N) {
		game2(m);
		return;
	}

	game1(k + 1, m);
	for (int i = 0; i < N; i++) {
		m[i][k] = 1 - m[i][k];
	}
	game1(k + 1, m);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	string s1;
	for (int i = 0; i < N; i++) {
		cin >> s1;
		for (int j = 0; j < N; j++) {
			if (s1[j] == 'H') { map[i][j] = 1; }
			else { map[i][j] = 0; }
		}
	}
	game1(0, map);
	cout << ans;
}
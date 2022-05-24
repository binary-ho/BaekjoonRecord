#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>

using namespace std;

int lim = 5;
int N, max_block = 1;
pair<int, int> map_original[20][20];



// 재귀적으로 실행되어야해
// 위 오른쪽 아래 왼쪽
void game(pair<int, int> map[][20], int index, vector<int> qiadraic) {
	bool updatede = false;
	if (index > 4) { return; }
	int command = qiadraic[index];
	if (command == 0) {
		// 위로 밀기
		//map[0][0]~map[0][N]까지 위로 한 칸씩
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].first == 0) { continue; }
				int k = 1;
				while (i - k >= 0 && map[i - k][j].first == 0) {
					map[i - k][j] = map[i - k + 1][j];
					map[i - k + 1][j] = { 0, 0 };
					k++;
				}
				if (i - k < 0) { continue; }
				if (map[i - k][j].first == map[i - k + 1][j].first && map[i - k][j].second < index + 1) {
					// 이번 회차에서는 한번만 더해져라
					map[i - k][j].first *= 2;
					map[i - k][j].second = index + 1;
					map[i - k + 1][j] = { 0, 0 };
					if (max_block < map[i - k][j].first) { max_block = map[i - k][j].first; updatede = true; }
				}
			}
		}
	}
	else if (command == 1) {
		// 아래로 밀기
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].first == 0) { continue; }
				int k = 1;
				while (i + k < N && map[i + k][j].first == 0) {
					map[i + k][j] = map[i + k - 1][j];
					map[i + k - 1][j] = { 0,0 };
					k++;
				}
				if (i + k >= N) { continue; }
				if (map[i + k][j].first == map[i + k - 1][j].first && map[i + k][j].second < index + 1) {
					map[i + k][j].first *= 2;
					map[i + k][j].second = index + 1;
					map[i + k - 1][j] = { 0,0 };
					if (max_block < map[i + k][j].first) {
						max_block = map[i + k][j].first; updatede = true;
					}
				}
			}
		}
	}
	else if (command == 2) {
		// 왼쪽으로 밀죠
		for (int j = 1; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (map[i][j].first == 0) { continue; }
				int k = 1;
				while (j - k >= 0 && map[i][j - k].first == 0) {
					map[i][j - k] = map[i][j - k + 1];
					map[i][j - k + 1] = { 0, 0 };
					k++;
				}
				if (j - k < 0) { continue; }
				if (map[i][j - k].first == map[i][j - k + 1].first && map[i][j - k].second < index + 1) {
					// 이번 회차에서는 한번만 더해져라
					map[i][j - k].first *= 2;
					map[i][j - k].second = index + 1;
					map[i][j - k + 1] = { 0, 0 };
					if (max_block < map[i][j - k].first) {
						max_block = map[i][j - k].first; updatede = true;
					}
				}
			}
		}
	}
	else if (command == 3) {
		for (int j = N - 2; j >= 0; j--) {
			for (int i = 0; i < N; i++) {
				if (map[i][j].first == 0) { continue; }
				int k = 1;
				while (j + k < N && map[i][j + k].first == 0) {
					map[i][j + k] = map[i][j + k - 1];
					map[i][j + k - 1] = { 0,0 };
					k++;
				}
				if (j + k >= N) { continue; }
				if (map[i][j + k].first == map[i][j + k - 1].first && map[i][j + k].second < index + 1) {
					map[i][j + k].first *= 2;
					map[i][j + k].second = index + 1;
					map[i][j + k - 1] = { 0,0 };
					if (max_block < map[i][j + k].first) {
						max_block = map[i][j + k].first; updatede = true;
					}
				}
			}
		}
	}
	/*if (updatede == true) {
		cout << "초기화 발생 조합: ";
		for (auto a : qiadraic) {
			cout << a << ' ';
		}
		cout << "의 " << index << "번째" <<'\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j].first << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}*/
	game(map, index + 1, qiadraic);
}

//100000 1024 - 1까지
void make_qiadraic(int num) {
	vector<int> result(lim);
	for (int i = 0; i < lim; i++) {
		result[i] = (num & 3);
		num >>= 2;
	}
	pair<int, int> map[20][20];
	memmove(map, map_original, sizeof(map));
	game(map, 0, result);
	//delete[] map;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			map_original[i][j] = { num, 0 };
			if (max_block < num) { max_block = num; }
		}
	}
	// 00000 11111 33333 4진수 비트마스킹
	for (int i = 0; i < 1024; i++) { make_qiadraic(i); }
	// 3 2 1 2 1
	/*vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(1);
	game(map_original, 0, vec);*/
	cout << max_block;
}
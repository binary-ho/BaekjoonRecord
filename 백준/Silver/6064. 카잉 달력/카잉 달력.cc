#include<iostream>
//#include <string>
//#include <stack>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include<cmath>
using namespace std;
//long long A[10][1000];


int Go(int M, int N, int x, int y) {
	x -= 1;
	y -= 1;
	int range = M * N;
	for (int i = x; i < range; i+=M) {
		if (i % N == y) {
			return i+1;
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	int M, N, x, y;
	while (T--) {
		cin >> M >> N >> x >> y;
		cout << Go(M, N, x, y) << '\n';
	}
	return 0;
}
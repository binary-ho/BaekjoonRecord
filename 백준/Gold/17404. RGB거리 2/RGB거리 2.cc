#include<iostream>
//#include <string>
//#include <stack>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include<cmath>
using namespace std;
int A[1001][3];
int D[1001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	int ans = 1000*1000+1;
	// D[i][0] = min(D[i-1][1] + D[i-1][2]) + A[i][0]; 이런 식으로 해주면 되는데 어떻게 했더라
	// 아 몇개를 그냥 고자로 만들어줘
	for (int g = 0; g < 3; g++) {
		for (int i = 2; i <= N; i++) {
			for (int j = 0; j < 3; j++) {
				if (g == j) {
					D[1][j] = A[1][j];
				}
				else {
					D[1][j] = 1001;
				}
				D[i][0] = min(D[i - 1][1], D[i - 1][2]) + A[i][0];
				D[i][1] = min(D[i - 1][0], D[i - 1][2]) + A[i][1];
				D[i][2] = min(D[i - 1][0], D[i - 1][1]) + A[i][2];
			}
		}
		for (int j = 0; j < 3; j++) {
			if (g == j) {
				D[N][j] = 1000*1000+1;
			}
		}
		if (D[N][0] <ans) {
			ans = D[N][0];
		}
		if (D[N][1] < ans) {
			ans = D[N][1];
		}
		if (D[N][2] < ans) {
			ans = D[N][2];
		}
	}

	cout << ans;
	return 0;
}
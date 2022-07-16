#include <iostream>
//#include <string>
//#include <stack>
#include <vector>
//#include <algorithm>
//#include <queue>
using namespace std;
int D[100000];
int P[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	// 1. 한번 무시하면 그 해당하는 곳의 D[i][1] = 1;을 한다
	// 무시하려면 근데 1이 추가가 안 되어야함
	// D[1][1]은 한번 무시한 버젼 그러면 D[2]
	// <제거기능 기록은 답이 아닌듯? 포기>
	// 2. 하나씩 0처리 해볼까? 시간이 오래 걸리기야는 하겠는데..
	// 그리고 크기가 10만 x 만 사이즈 배열은 너무 커 감당이 안 돼
	// 3. 임시 보관함을 만들어보자 N 세제곱이지만 2초니까 한번 해보자구
	D[0] = vec[0];
	for (int i = 1; i < N; i++) {
		D[i] = vec[i];
		if (D[i] < D[i - 1] + vec[i]) {
			D[i] = D[i - 1] + vec[i];
		}
	}
	P[N - 1] = vec[N - 1];
	if (N > 1) {
		for (int i = N - 2; 0 <= i; i--) {
			P[i] = vec[i];
			if (P[i] < P[i + 1] + vec[i]) {
				P[i] = P[i + 1] + vec[i];
			}
		}
	}

	int ans1 = vec[0];
	for (int i = 0; i < N; i++) {
		if (ans1 < D[i]) {
			ans1 = D[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (ans1 < P[i]) {
			ans1 = P[i];
		}
	}
	if (N > 2) {
		for (int i = 1; i <= N - 2; i++) {
			if (ans1 < D[i - 1] + P[i + 1]) {
				ans1 = D[i - 1] + P[i + 1];
			}
		}
	}
	cout << ans1;
}
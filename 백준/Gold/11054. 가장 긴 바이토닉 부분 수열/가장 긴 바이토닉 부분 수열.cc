#include <iostream>
//#include <string>
//#include <stack>
#include <vector>
//#include <algorithm>
//#include <queue>
using namespace std;
int Back[1000];
int Front[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> vec(N);
	
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	//D[0] = vec[0];
	for (int i = N-1; i >= 0; i--) {
		Back[i] = 1;
		for (int j = i+1; j < N; j++) {
			if (vec[i] > vec[j] && Back[i] < Back[j] + 1) {
				Back[i] = Back[j] + 1;
			}
		}
	}
	for (int i = 0; i <N; i++) {
		Front[i] = 1;
		for (int j = 0; j < i; j++) {
			if (vec[i] > vec[j] && Front[i] < Front[j] + 1) {
				Front[i] = Front[j] + 1;
			}
		}
	}
	int ans = Front[0] + Back[0] -1;
	for (int i = 1; i < N; i++) {
		if (ans < Front[i] + Back[i] -1) {
			ans = Front[i] + Back[i] -1;
		}
	}
	cout << ans;
}

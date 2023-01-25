#include <iostream>
//#include <string>
//#include <stack>
#include <vector>
//#include <algorithm>
//#include <queue>
using namespace std;
long long D[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K;
	cin >> N;
	cin >> K;
	long long div = 1000000000;
	for (int i = 1; i <= N; i++) {
		D[i][1] = 1;
    }
	for (int k = 1; k <= K; k++) {
		D[1][k] = k;
	}
	for (int i = 2; i <= N; i++) {
        for(int j =2; j<=K;j++){
            D[i][j]=(D[i-1][j]+
                     D[i][j-1])%div;
        }
	}
	cout << D[N][K];
}
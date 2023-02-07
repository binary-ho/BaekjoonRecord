#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
//#include <cstring>
//#include <stack>
//#include <bitset>

using namespace std;

int N,M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	multiset<int> s;
	int input;
	for (int i = 0; i < N + M; i++) {
		cin >> input;
		s.insert(input);
	}
	for (auto& elem : s) {
		cout << elem << ' ';
	}
}
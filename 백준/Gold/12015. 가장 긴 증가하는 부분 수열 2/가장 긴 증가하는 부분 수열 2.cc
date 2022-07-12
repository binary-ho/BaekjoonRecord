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

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<int> vec_N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		auto itr = lower_bound(vec_N.begin(), vec_N.end(), input);
		if (itr == vec_N.end()) {
			vec_N.push_back(input);
		}
		else {
			*itr = input;
		}
	}
	cout << vec_N.size();
}
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
//#include <cstring>
//#include <stack>
//#include <bitset>

using namespace std;

bool check[1002][1002];

struct Rock {
	int A, B, C;
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;
	int N = a + b + c;
	if (N % 3 != 0) {
		cout << 0;
		return 0;
	}
	int avg = N / 3;
	if (a == avg && b == avg && c == avg) {
		cout << 1;
		return 0;
	}
	Rock R1;
	R1.A = min({ a, b, c });
	R1.C = max({ a,b,c });
	R1.B = N - R1.A - R1.C;
	while (1) {
		a = R1.A; b = R1.B; c = R1.C;
		if (b == avg && c == a * 2) { break; }
		if (a != avg && c != avg && check[a][c] == false) {
			check[a][c] = true;
			c -= a;
			a += a;
		}
		else if (a != avg && c != avg && check[a][c] == true) {
			if (check[a][b] == false) {
				check[a][b] = true;
				b -= a;
				a += a;
			}
			else { break; }
		}
		else if (c == a * 2 && b!=avg) { 
			check[a][b] = true;
			b -= a;
			a += a;
		}
		else { break; }
		R1.A = min({ a, b, c });
		R1.C = max({ a,b,c });
		R1.B = N - R1.A - R1.C;
	}
	if (R1.A == avg && R1.B == avg && R1.C == avg) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}
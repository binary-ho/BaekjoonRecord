#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
#include<map>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

map<ll, ll> king;
ll arr[3] = { 0, 1, 1};
ll div_num = 1000000007;

ll fiv(ll N) {
	if (N < 3) {
		return arr[N];
	}
	if (king.count(N) == 1) {
		return king[N];
	}
	if (N%2 == 0) {
		ll n = N / 2;
		ll f1 = fiv(n - 1);
		ll f2 = fiv(n);
		king[N] = (2*f1 + f2) * f2;
		king[N] %= div_num;
		return king[N];
	}
	else {
		ll n = (N + 1) / 2;
		ll f1 = fiv(n);
		ll f2 = fiv(n - 1);
		king[N] = (f1*f1) + (f2*f2);
		king[N] %= div_num;
		return  king[N];
	}
}

int main() {
	ll input; bool is_odd_input;
		cin >> input;
		cout << fiv(input);
	
}

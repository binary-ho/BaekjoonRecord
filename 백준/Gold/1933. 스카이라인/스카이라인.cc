#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;

#define p vector<pair<int, int>>

typedef struct Building {
	int l, h, r;
}building;

int N, l, h, r;
vector<building> vec_b;

void go_push(p &ans, int hight, int x) {
	if (!ans.empty()) {
		if (ans.back().first == hight) { return; }
		else if (ans.back().second == x) { ans.back().first = hight; return; }
	}
	ans.push_back({ hight, x });
}


p merge(p l, p r) {	
	p ans;
	int i = 0;
	int j = 0;

	int h1 = 0;
	int h2 = 0;
	while (i < l.size() && j < r.size()) {
		if (l[i].second < r[j].second) {
			h1 = l[i].first;
			int h = max(h1, h2);
			go_push(ans, h, l[i].second);
			i++;
		}
		else {
			h2 = r[j].first;
			int h = max(h1, h2);
			go_push(ans, h, r[j].second);
			j++;
		}
	}
	while (i < l.size()) {
		go_push(ans, l[i].first, l[i].second);
		i++;
	}
	while (j < r.size()) {
		//ans.push_back(r[j]);
		go_push(ans, r[j].first, r[j].second);
		j++;
	}
	return ans;
}


p go(int s, int e) {
	if (s == e) {
		p ans;
		ans.push_back({ vec_b[s].h, vec_b[s].l});
		ans.push_back({ 0, vec_b[e].r });
		return ans;
	}
	int mid = (s + e) / 2;
	auto l = go(s, mid);
	auto r = go(mid + 1, e);
	return merge(l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	
	building b;
	for (int i = 0; i < N; i++) {
		cin >> b.l >> b.h >> b.r;
		vec_b.push_back(b);
	}
	sort(vec_b.begin(), vec_b.end(), [](building& u, building& v) { 
		return tuple(u.l, u.h, u.r) < tuple(v.l, v.h, v.r);
	});

	auto ans = go(0, N - 1);
	for (auto &e : ans) {
		cout << e.second << ' ' << e.first << ' ';
	}
	cout << '\n';
	return 0;
}
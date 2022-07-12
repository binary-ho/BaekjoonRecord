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
long long arr[500001];
long long arr2[500001];

int N;
long long cnt = 0;

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start; int j = mid +1; int k = start;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) { arr2[k++] = arr[i++];}
		else { cnt += (long long)(mid-i+1); arr2[k++] = arr[j++]; }
	}
	// 위의 while문이 끝났을 떄 왼쪽이 남았을지 오른쪾이 남았을지. 나머지 채우기 구현
	while (i <= mid) { arr2[k++] = arr[i++]; }
	while (j <= end) { arr2[k++] = arr[j++];}
	for (int h = start; h <= end; h++) {
		arr[h] = arr2[h];
	}
}

void partition(int start, int end) {
	if (start == end) { return; }
	int mid = (start + end) / 2;
	partition(start, mid);
	partition(mid+1, end);
	merge(start, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	partition(0, N-1);
	cout << cnt;
}

// 교훈: 일반 배열처럼 0~N바로 전까지 이렇게 짜지말고,
// 실제로 건들이는 값들만 이용하자 0<= 에서 <=N 이렇게
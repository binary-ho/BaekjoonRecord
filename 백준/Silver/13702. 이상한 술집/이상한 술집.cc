#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N, K;
int arr[10001];

int main() {
    cin >> N >> K;
    long long end = (1<<31)-1;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    long long mid, cnt, start = 0, ans = 0;
    while(start <= end) {
        cnt = 0;
        mid = ((start+end)>>1);
        if(mid==0) {
            cnt = K;
        } else {
            for(int i = 0; i < N; i++) cnt += arr[i]/mid;
        }
        if(cnt >= K) {
            if(ans < mid) ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << ans << '\n';
}
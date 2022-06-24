#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
long long n, k;
int main() {
    cin >> n >> k;
    vector<long long> vec(n, 0);
    // 100 -> 0
    // 100 200 -> 200*1
    // 100 200 300 -> 300 * 2
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    long long ans = 0;
    for(long long i = 0; i < n; i++) {
        if(i<k) ans += i*vec[i];
        else ans += k*vec[i];
    }
    cout << ans;
}
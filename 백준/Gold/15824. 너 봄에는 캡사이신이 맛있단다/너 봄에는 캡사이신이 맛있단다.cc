#include<iostream>
#include<vector>
#include <algorithm>

#define DIV 1000000007
using namespace std;
int N;
long long two_power[300001];
int main() {
    cin >> N;
    vector<long long> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    long long ans = 0;
    two_power[0] = 1;
    for (int i = 1; i < N; i++) { two_power[i] = two_power[i - 1] * 2; two_power[i] %= DIV; }
    for (int i = 0; i < N; i++) {
        ans += (two_power[i] - 1) * (vec[i] - vec[N-i-1]);
        ans %= DIV;
    }
    cout << ans;
}
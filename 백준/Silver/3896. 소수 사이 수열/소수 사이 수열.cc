#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int T, k;
vector<int> prime;

// 미리 만들어둔 소수 함수
vector<int> getPrimeSet(int N) {
    int N2 = (int) sqrt(N);
    vector<bool> check(N+1, false);
    for(int i = 2; i <= N2; i++) {
        if(check[i]) continue;
        for(int j = i*i; j <= N; j += i) {
            check[j] = true;
        }
    }

    vector<int> ans;
    for(int i = 2; i <= N; i++) if(!check[i]) ans.emplace_back(i);
    return ans;
}

int main() {
    prime = getPrimeSet(1299709);
    cin >> T;
    while(T--) {
        cin >> k;
        auto itr1 = lower_bound(prime.begin(), prime.end(), k);
        auto itr2 = itr1 - 1;
        if(itr1 != prime.begin() && k != *itr1) cout << *itr1 - *itr2 << '\n';
        else cout << 0 << '\n';
    }
}
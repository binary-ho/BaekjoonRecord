#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

long long gcd(long long A, long long B) {
    if(B != 0) return gcd(B, A%B);
    return A;
}

// 함유 높은 것 부터 넣는다
int main() {
    long long N, M, w, v;
    cin >> N >> M;
    vector<pair<double, pair<long long, long long>>> vec;
    for(int i = 0; i < N; i++) {
        cin >> w >> v;
        vec.push_back({(double)v/w, {w, v}});
    }
    sort(vec.begin(), vec.end(), greater<>());
    long long sugar = 0, denominator = 0, numberator = 0;
    for(auto p : vec) {
        if(M >= p.second.first) {
            M -= p.second.first;
            sugar = sugar + p.second.second;
        } else {
            denominator = p.second.first;
            numberator = M * p.second.second + sugar * denominator;
            break;
        }
    }
    if(denominator == 0) {
        cout << sugar << "/" << 1 << '\n';
        return 0;
    }
    long long gcd_int = gcd(numberator, denominator);
    cout << numberator/gcd_int << "/" << denominator/gcd_int << '\n';
}

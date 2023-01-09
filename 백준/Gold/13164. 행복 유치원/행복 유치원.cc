#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    long long sum = 0;
    cin >> N >> K;
    vector<int> vec(N), diff(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        if (i == 0) continue;
        diff[i - 1] = vec[i] - vec[i - 1];
        sum += diff[i - 1];
    }

    std::sort(diff.begin(), diff.end(), greater<>());
    for (int i = 0; i < K - 1; i++) {
        sum -= diff[i];
    }
    cout << sum;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> crane(N);
    for (int i = 0; i < N; i++) cin >> crane[i];
    std::sort(crane.begin(), crane.end(), greater<>());

    cin >> M;
    vector<int> box(M);
    for (int i = 0; i < M; i++) { 
        cin >> box[i]; 
        if (box[i] > crane[0]) {
            cout << -1;
            return 0;
        }
    }
    std::sort(box.begin(), box.end(), less<>());

    int ans = 0;
    while (1) {
        ans++;
        for (int crane_now : crane) {
            auto itr = std::upper_bound(box.begin(), box.end(), crane_now);
            if (itr == box.begin()) break;
            box.erase(itr - 1);
        }
        if (box.empty()) {
            cout << ans;
            return 0;
        }
    }
}

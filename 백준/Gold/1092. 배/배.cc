#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> crane(N);
    for (int i = 0; i < N; i++) cin >> crane[i];

    cin >> M;
    vector<int> box(M);
    for (int i = 0; i < M; i++) cin >> box[i];

    std::sort(crane.begin(), crane.end(), greater<>());
    std::sort(box.begin(), box.end(), less<>());

    int ans = 0;
    bool isRemove;
    while (1) {
        isRemove = false;
        ans++;
        for (int crane_now : crane) {
            auto itr = std::upper_bound(box.begin(), box.end(), crane_now);
            if (itr == box.begin()) break;
            box.erase(itr - 1);
            isRemove = true;
        }
        if (!isRemove) {
            cout << -1;
            return 0;
        }
        if (box.empty()) {
            cout << ans;
            return 0;
        }
    }
}

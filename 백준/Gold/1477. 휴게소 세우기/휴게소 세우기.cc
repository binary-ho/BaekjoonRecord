#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> vec(N), diffs;
    for (int i = 0; i < N; i++) cin >> vec[i];
    vec.emplace_back(0);
    std::sort(vec.begin(), vec.end());
    if (vec.back() != L) vec.emplace_back(L);
    for (int i = 1; i < vec.size(); i++) {
        diffs.emplace_back(vec[i] - vec[i - 1]);
    }
    std::sort(diffs.begin(), diffs.end(), greater<>());
    int cut;
    int start = 1, end = L, mid;
    while (start <= end) {
        cut = 0;
        mid = (start + end) / 2;
        for (int diff : diffs) {
            if (mid >= diff) break;
            cut += (diff - 1) / mid;
            if (cut > M) break;
        }
        if (cut > M) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << start;
}

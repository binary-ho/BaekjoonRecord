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
//    for (int i : vec) cout << i << " ";
//    cout << '\n';
    int ans = 0;
    for (int i = 1; i < vec.size(); i++) {
        int diff = vec[i] - vec[i - 1];
        ans = max(ans, diff);
        diffs.emplace_back(vec[i] - vec[i - 1]);
    }
    std::sort(diffs.begin(), diffs.end(), greater<>());
    int cut;
    int start = 1, end = L, mid;
    while (start <= end) {
        cut = 0;
        mid = (start + end) / 2;
//        cout << start << " " << end << " " << mid << ": ";
        for (int diff : diffs) {
            if (mid >= diff) break;
            cut += (diff - 1) / mid;
//            cout << "(" << diff << " "<< diff / mid << ") ";
            // 이 m이 만약에 M보다 크다면 잘못됐어. 더 큰 mid가 필요해
        }
//        cout << cut << '\n';
        if (cut > M) {
            start = mid + 1;
        } else {
            end = mid - 1;
            // 똑같이 M개 세워서 더 최소인 것을 원하지
            if (cut == M) ans = min(ans, mid);
        }
    }
    cout << start;
}

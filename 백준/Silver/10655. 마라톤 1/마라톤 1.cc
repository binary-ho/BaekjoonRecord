#include <iostream>
#include <vector>

using namespace std;
int N;

int main() {
    cin >> N;
    vector<pair<int, int>> check_point(N, {0, 0});
    int idx_temp = -1, max_earn = 0, normal_earn, erase_earn;
    for(int i = 0; i < N; i++) {
        cin >> check_point[i].first >> check_point[i].second;
        if(i <= 1) continue;
        // 원래 걸렸을 거리와, 그게 없을 때의 거리
        normal_earn = abs(check_point[i-2].first - check_point[i-1].first) + abs(check_point[i-2].second - check_point[i-1].second)
                + abs(check_point[i-1].first - check_point[i].first) + abs(check_point[i-1].second - check_point[i].second);
        erase_earn = abs(check_point[i-2].first - check_point[i].first) + abs(check_point[i-2].second - check_point[i].second);
        if(normal_earn <= erase_earn) continue;
        if(normal_earn - erase_earn > max_earn) {
            max_earn = normal_earn - erase_earn;
            idx_temp = i - 1;
        }
    }
    if(idx_temp != -1) check_point.erase(check_point.begin() + idx_temp);
    int ans = 0;
    for(int i = 0; i < N - 2; i++) {
        ans += abs(check_point[i].first - check_point[i+1].first) + abs(check_point[i].second - check_point[i+1].second);
    }
    cout << ans;
}
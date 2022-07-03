#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W, N, h, w;
    cin >> H >> W >> N;
    vector<pair<int, int>> vec(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i].first >> vec[i].second;
    }
    int ans = 0, temp;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            temp = vec[i].first * vec[i].second + vec[j].first * vec[j].second;
            if((vec[i].first + vec[j].first <= H && vec[i].second <= W && vec[j].second <= W)
            || (vec[i].second + vec[j].second <= W) && vec[i].first <= H && vec[j].first <= H) {
                if(ans < temp) ans = temp;
            }
            if((vec[i].first + vec[j].first <= W && vec[i].second <= H && vec[j].second <= H)
               || (vec[i].second + vec[j].second <= H) && vec[i].first <= W && vec[j].first <= W) {

                if(ans < temp) ans = temp;
            }
            if ((vec[i].first + vec[j].second <= H && vec[i].second <= W && vec[j].first <= W)
            || (vec[i].second + vec[j].first <= W) && vec[i].first <= H && vec[j].second <= H) {

                if(ans < temp) ans = temp;
            }
            if ((vec[i].first + vec[j].second <= W && vec[i].second <= H && vec[j].first <= H)
                || (vec[i].second + vec[j].first <= H) && vec[i].first <= W && vec[j].second <= W) {

                if(ans < temp) ans = temp;
            }
        }
    }
    cout << ans;
}

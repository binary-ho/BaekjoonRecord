#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int M,  N, evol[3], idx, temp, cnt;
vector<int> evol_vec[3];
int map[701][701];
int main() {
    cin >> M >> N;
    while(N--) {
        cin >> evol[0] >> evol[1] >>evol[2];
        if(evol[1] + evol[2] != 0) evol_vec[1].emplace_back(evol[1] + evol[2]);
        if(evol[2] != 0) evol_vec[2].emplace_back(evol[2]);
    }
    sort(evol_vec[1].begin(), evol_vec[1].end());
    sort(evol_vec[2].begin(), evol_vec[2].end());
    for(int point = 1; point <= 2; point++) {
        cnt = 0;
        if(evol_vec[point].empty()) continue;
        auto itr = evol_vec[point].begin();
        for(int j = M -1; j >= 0; j--) {
            map[0][j] += (evol_vec[point].end() - itr);
            cnt++;
            if(cnt == *itr) {
                itr = upper_bound(evol_vec[point].begin(), evol_vec[point].end(), cnt);
            }
            if(itr == evol_vec[point].end()) break;
        }
        for(int i = 1; i < M; i++) {
            map[i][0] += (evol_vec[point].end() - itr);
            cnt++;
            if(cnt == *itr) {
                itr = upper_bound(evol_vec[point].begin(), evol_vec[point].end(), cnt);
            }
            if(itr == evol_vec[point].end()) break;
        }
    }
    for(int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if(j==0) {
                cout << map[i][j] + 1 << " ";
                continue;
            }
            cout << map[0][j] + 1 << " ";
        }
        cout << '\n';
    }
}

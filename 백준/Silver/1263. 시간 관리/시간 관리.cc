#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> time_table;

int main() {
    cin >> N;
    int cost, end;
    for(int i = 0; i < N; i++) {
        cin >> cost >> end;
        if(end - cost < 0) {
            cout << -1; return 0;
        }
        time_table.emplace_back(end, cost);
    }
    sort(time_table.begin(), time_table.end());
    int time = 0, min_start = 1000001;
    for(auto p : time_table) {
        if(time > p.first - p.second) {
            cout << -1;
            return 0;
        }
        time += p.second;
        if(p.first - time < min_start) {
            min_start = p.first - time;
        }
    }
    if(time > 1000000000 || min_start < 0) {
        cout << -1; return 0;
    }
    cout << min(min_start, time_table[N-1].first - time);
}
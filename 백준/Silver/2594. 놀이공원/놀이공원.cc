#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> vec;

int main() {
    cin >> N;
    int start, end;
    for(int i = 0; i < N; i++) {
        cin >> start >> end;
        vec.emplace_back((start/100)*60 + start%100 - 10, (end/100)*60 + end%100 + 10);
    }
    sort(vec.begin(), vec.end());
    vec.emplace_back(1320, 1320);
    start = end = 600;
    int ans = 0, temp;
    for(auto p : vec) {
        if(end < p.first) {
            temp = (p.first - end);
            if(ans < temp) ans = temp;
        }
        start = p.first;
        if(end < p.second) end = p.second;
    }
    cout << ans;
}
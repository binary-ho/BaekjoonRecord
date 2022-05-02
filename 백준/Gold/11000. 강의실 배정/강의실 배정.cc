#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first != p2.first) return p1.first < p2.first;
    else return p1.second < p2.second;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> vec(N, {0, 0});
    for(int i = 0; i < N; i++) cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end(), cmp);
    int start = 1, end = N, mid = 1;
    while(start < end) {
        mid = (start + end) / 2;
        bool pass = true;
        priority_queue<int> que;
        for(pair<int, int> p : vec) {
            if(!que.empty() && -que.top() <= p.first) {
                que.pop();
            }
            que.push(-p.second);
            if(que.size() > mid) {
                pass = false;
                break;
            }
        }
        if(!pass) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    cout << end;
}
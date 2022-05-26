#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

bool check[2][100000];
int main() {
    int N, k;
    cin >> N >> k;
    string bridge[2];
    cin >> bridge[0] >> bridge[1];
    // bridge, box_num, phase
    queue<tuple<int, int, int>> que;
    que.push(make_tuple(0, 0, 0)); // 이렇게 가니까 N 이상
    int bridge_now, box_now, phase_now;
    while(!que.empty()) {
        tie(bridge_now, box_now, phase_now) = que.front();
        que.pop();
        if(box_now < phase_now) continue;
        if(box_now + 1 >= N || box_now + k >= N) {
            cout << 1;
            return 0;
        }
        if(box_now > 0 && bridge[bridge_now][box_now - 1] == '1' && !check[bridge_now][box_now - 1]) {
            check[bridge_now][box_now - 1] = true;
            que.push(make_tuple(bridge_now, box_now - 1, phase_now + 1));
        }
        if(bridge[bridge_now][box_now + 1] == '1' && !check[bridge_now][box_now + 1]) {
            check[bridge_now][box_now + 1] = true;
            que.push(make_tuple(bridge_now, box_now + 1, phase_now + 1));
        }
        if(bridge[1 - bridge_now][box_now + k] == '1' && !check[1 - bridge_now][box_now + k]) {
            check[1 - bridge_now][box_now + k] = true;
            que.push(make_tuple(1 - bridge_now, box_now + k, phase_now + 1));
        }
    }
    cout << 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N, M, num, city_now, city_next, mask_now, ans;
int two_power[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int population[11];
vector<int> vec[11];
queue<int> que;

pair<int, int> bfs(int constituency, int idx_start, int candidate_now) {
    int check = 0, cnt = 1, sum = population[idx_start + 1];
    que.push(idx_start + 1);
    check |= (1 << idx_start);
    //cout << "bfs start " << constituency  << " " << idx_start << " " << candidate_now << " " << check << '\n';
    while(!que.empty()) {
        city_now = que.front();
        que.pop();
        for(int i = 0; i < vec[city_now].size(); i++) {
            city_next = vec[city_now][i];
            mask_now = (1 << (city_next - 1));
            // 이어져 있고, 안 가봤으며, 나와 같을 때만
            // 1일떄는 1 이상이여야 하고 0일 떄는 0만 됨
            // 1일때는 0이면 안 되고 0일 때는 1 이상이면 안 돼
            if((check & mask_now) >= 1) continue;
            if(candidate_now == 1) {
                if((constituency & mask_now) == 0) continue;
            } else {
                if((constituency & mask_now) != 0)continue;
            }
            que.push(city_next);
            check |= mask_now;
            //cout << "push " << city_next << " " << (check & mask_now) << '\n';
            cnt++;
            sum+=population[city_next];
        }
    }
    return {cnt, sum};
}

void init_dfs(int constituency, int one_cnt) {
    int cnt = 0, ret1, ret2;
    // 1부터

    for(int i = 0; i < N; i++) {
        if((constituency & (1 << i)) == 0) continue;
        tie(cnt, ret1) = bfs(constituency, i, 1);
        break;
    }
    if(cnt != one_cnt) return;
    for(int i = 0; i < N; i++) {
        if((constituency & (1 << i)) >= 1) continue;
        tie(cnt, ret2) = bfs(constituency, i, 0);
        break;
    }
    if(cnt != N - one_cnt) return;
    //cout << "성공! " << constituency <<  abs(ret1 - ret2) << '\n';
    if(ans > abs(ret1 - ret2)) ans = abs(ret1 - ret2);
}

void selection(int idx, int num_now, int one_cnt) {
    if(idx == N) {
        if(num_now == 0 || num_now == two_power[N] - 1) return;
        //cout << num_now << '\n';
        init_dfs(num_now, one_cnt);
        return;
    }
    for(int i = 0; i < 2; i++) {
        selection(idx+1, (num_now << 1) + i, one_cnt + i);
    }
}


int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> population[i];
    }
    // 조합으로 골라볼까
    for(int i = 1; i <= N; i++) {
        cin >> M;
        for(int j = 0; j < M; j++) {
            cin >> num;
            vec[i].emplace_back(num);
        }
    }
    ans = 1001;
    selection(0, 0, 0);
    if(ans == 1001) ans = -1;
    cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N, dest;
vector<int> vec[101];
vector<int> ans;
bool check[101];
void dfs2(int node_now) {
    if(!check[node_now]) {
        return;
    }
    check[node_now] = false;
    ans.emplace_back(node_now);
    if(!vec[node_now].empty()) dfs2(vec[node_now][0]);
    return;
}
void dfs(int node_now) {
    if(check[node_now]) {
        dfs2(node_now);
        return;
    }
    check[node_now] = true;
    if(!vec[node_now].empty()) dfs(vec[node_now][0]);
    return;
}

int main() {
    // 100개 중에 1개
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> dest;
        if(i==dest) ans.emplace_back(i);
        else vec[i].emplace_back(dest);
    }

    for(int i = 1; i <= N; i++) {
        memset(check, false, sizeof(check));
        dfs(i);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for(int num: ans) {
        cout << num << '\n';
    }
}
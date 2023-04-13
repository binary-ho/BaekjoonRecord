#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

int ticketsCnt, icn;
vector<string> airport, ans;
vector<pair<int, int>> vec[10001];
map<string, int> airmap;
stack<int> st;
bool stop, check[10001];

void dfs(int now, int cnt) {
    if (stop) return;
    if (cnt == ticketsCnt) {
        stop = true;
        while (!st.empty()) {
            ans.emplace_back(airport[st.top()]);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return;
    }
    
    for (int i = 0; i < vec[now].size(); i++) {
        int next = vec[now][i].first;
        int ticket = vec[now][i].second;
        if (check[ticket]) continue;
        st.push(next);
        check[ticket] = true;
        dfs(next, cnt + 1);
        check[ticket] = false;
        if (!st.empty()) st.pop();
    }
}

// 정렬
// 모두 사용해서 도착 모두 사용해서 도착 모두 사용해서 도착 dfs?
// 알파벳 순으로 순서를 알면 좋을 것 같다 그리고 숫자를 부여 해주면 좋을것 같다.
vector<string> solution(vector<vector<string>> tickets) {
    ticketsCnt = tickets.size();
    sort(tickets.begin(), tickets.end());
    
    for (vector<string> v : tickets) {
        airport.emplace_back(v[0]);
        airport.emplace_back(v[1]);
    }
    sort(airport.begin(), airport.end());
    airport.erase(unique(airport.begin(), airport.end()), airport.end());
    
    // 번호 부여
    for (int i = 0; i < airport.size(); i++) {
        airmap[airport[i]] = i;
    }
    
    int start, dist;
    for (int i = 0; i < ticketsCnt; i++) {
        start = airmap[tickets[i][0]];
        dist = airmap[tickets[i][1]];
        vec[start].emplace_back(dist, i);
    }
    
    icn = airmap["ICN"];
    st.push(icn);
    dfs(icn, 0);
    return ans;
}
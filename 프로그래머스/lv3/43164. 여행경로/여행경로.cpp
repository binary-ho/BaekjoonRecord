#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct ticket {
    string name;
    bool check = false;
    
    ticket(string str) {
        name = str;
    }
}; 

map<string, vector<ticket>> mp;
vector<string> answer;
vector<string> ans;
int ticketCnt;
bool pass;

void dfs(string now, int cnt) {
    if (pass) return;
    if (cnt == ticketCnt) {
        pass = true;
        ans.insert(ans.begin(), answer.begin(), answer.end());
        return;
    }
    
    for (int i = 0; i < mp[now].size(); i++) {
        ticket &next = mp[now][i];
        if (next.check) continue;
        next.check = true;
        answer.push_back(next.name);
        dfs(next.name, cnt + 1);
        if (pass) return;
        answer.pop_back();
        next.check = false;
    }
}

bool cmp(vector<string> vec1, vector<string> vec2) {
    if (vec1[0].compare(vec2[0]) != 0) {
        return vec1[0] < vec2[0];
    } else {
        return vec1[1] < vec2[1];
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), cmp);

    for (vector<string> vec : tickets) {
        mp[vec[0]].push_back(ticket(vec[1]));
    }
    
    ticketCnt = tickets.size();
    
    answer.push_back("ICN");
    dfs("ICN", 0);
    return answer;
}
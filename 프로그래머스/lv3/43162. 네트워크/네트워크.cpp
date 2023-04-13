#include <string>
#include <vector>
#include <queue>
using namespace std;
bool check[201];

vector<int> vec[201];

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++) {
            if (i == j) continue;
            if (computers[i][j] == 1) {
                vec[i].emplace_back(j);
            }
        }
    }
    
    int nodeNow, nextNode, ans = 0;
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        ans++;
        que.push(i);
        check[i] = true;
        while (!que.empty()) {
            nodeNow = que.front();
            que.pop();
            
            for (int j = 0; j < vec[nodeNow].size(); j++) {
                nextNode = vec[nodeNow][j];
                if (check[nextNode]) continue;
                check[nextNode] = true;
                que.push(nextNode);
            }
        }
    }
    return ans;
}
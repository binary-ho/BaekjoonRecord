#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
// 일단 끊어졌냐도 문제임
// n이 작으니 그냥 세면서 확인해도 된다.
vector<int> tree[101];
int check[101];
queue<int> que;

int bfs(int start, int end, int phase) {
    if (phase == 2 && check[start] == 1) {
        return -1;
    }
    
    int ret = 1;
    que.push(start);
    check[start] = phase;
    
    int temp, treeNext;
    while (!que.empty()) {
        temp = que.front();
        que.pop();
        
        for (int i = 0; i < tree[temp].size(); i++) {
            treeNext = tree[temp][i];
            if (temp == start && treeNext == end) continue;
            
            if (check[treeNext] == phase) {
                continue;
            }
            
            if (check[treeNext] == 0) {
                check[treeNext] = phase;
                que.push(treeNext);
                ret++;
                continue;
            }
            
            return -1;
        }
    }
    
    while(!que.empty()) que.pop();
    return ret;
}

int solution(int n, vector<vector<int>> wires) {

    for (vector<int> wire : wires) {
        tree[wire[0]].push_back(wire[1]);
        tree[wire[1]].push_back(wire[0]);
    }

    int bfsRet[3], ans = 100;
    
    for (vector<int> wire : wires) {
        // 0 먼저, 1 차례
        memset(check, 0, sizeof(check));
        for (int phase = 1; phase <= 2; phase++) {
            bfsRet[phase] = bfs(wire[2 - phase], wire[phase - 1], phase);
        }
        
        if (bfsRet[1] != -1 && bfsRet[2] != -1) {
            if (ans > abs(bfsRet[1] - bfsRet[2])) {
                ans = abs(bfsRet[1] - bfsRet[2]);
            }
        }
    }
    
    return ans;
}
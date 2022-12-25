#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 60
using namespace std;

int N, prev_node[MAX], capacity[MAX][MAX], flow[MAX][MAX];
vector<int> pipe[MAX];

int getNum(char c) {
    return c - 'A';
}

int setFlow() {
    int minFlow = INF;
    for (int node_now = 25; node_now != 0; node_now = prev_node[node_now]) {
        // 흐를 수 있는 최소 유량 찾기
        minFlow = min(minFlow, capacity[prev_node[node_now]][node_now] - flow[prev_node[node_now]][node_now]);
    }

    for (int i = 25; i != 0; i = prev_node[i]) {
        flow[prev_node[i]][i] += minFlow;
        flow[i][prev_node[i]] -= minFlow;
    }
    return minFlow;
}

int getMaximumFlow() {
    int ans = 0;
    while(1) {
        for (int i = 0; i < MAX; i++) prev_node[i] = -1;
        queue<int> que;
        que.push(0);
        while(!que.empty()) {
            int node_now = que.front();
            que.pop();
            for (int i = 0; i < pipe[node_now].size(); i++) {
                auto next_node = pipe[node_now][i];
                if (capacity[node_now][next_node] - flow[node_now][next_node] == 0 || prev_node[next_node] != -1) continue;
                que.push(next_node);
                prev_node[next_node] = node_now;
                if (next_node == 25) break;
            }
        }
        if (prev_node[25] == -1) break;
        ans += setFlow();
    }
    return ans;
}

int main() {
    cin >> N;

    int pipeCapacity, srcInt, destInt;
    char src, dest;
    for (int i = 0; i < N; i++) {
        cin >> src >> dest >> pipeCapacity;
        srcInt = getNum(src);
        destInt = getNum(dest);
        pipe[srcInt].emplace_back(destInt);
        pipe[destInt].emplace_back(srcInt);
        capacity[srcInt][destInt] += pipeCapacity;
        capacity[destInt][srcInt] += pipeCapacity;
    }

    cout << getMaximumFlow();
    return 0;
}


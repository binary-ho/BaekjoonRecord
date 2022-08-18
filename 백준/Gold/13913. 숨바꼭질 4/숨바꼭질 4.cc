#include<iostream>
#include <string>
#include <stack>
#include <vector>
//#include <algorithm>
#include <queue>
#include<cstring>
using namespace std;

int N, K;
vector<int> vec[200002];
bool check[200002];
int dist[200002];
bool stop_bfs = false;
int prev_num[200002];

void bfs(int i) {
    queue<int> que;
    que.push(i);
    check[i] = true;
    dist[i] = 0;
    while (!que.empty()) {
        int node_now = que.front();
        que.pop();
        if (node_now == 0) {
            vec[node_now].push_back(node_now + 1);
        }
        else if (node_now <= 50002){
            vec[node_now].push_back(node_now + 1);
            vec[node_now].push_back(node_now - 1);
            vec[node_now].push_back(node_now * 2);
        }
        else {
            vec[node_now].push_back(node_now + 1);
            vec[node_now].push_back(node_now - 1);
        }
        for (int j = 0; j < vec[node_now].size(); j++) {
            int next_node = vec[node_now][j];
            if (next_node == K) {
                prev_num[next_node] = node_now;
                dist[next_node] = dist[node_now] + 1;
                stop_bfs = true;
                break;
            }
            if (check[next_node] == false) {
                que.push(next_node);
                dist[next_node] = dist[node_now] + 1;
                check[next_node] = true;
                prev_num[next_node] = node_now;
            }
        }
        if (stop_bfs == true) {
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    if (N == K) {
        cout << 0 << '\n';
        cout << N;
        return 0;
    }
    
    bfs(N);
    
    stack<int> stack;
    int trace = K;
    while (trace != N) {
        stack.push(prev_num[trace]);
        trace = prev_num[trace];
    }

    cout << dist[K] << '\n';

    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << K;
    
}
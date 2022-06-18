#include<iostream>
#include <string>
#include <stack>
#include <vector>
//#include <algorithm>
#include <queue>
#include<cstring>
using namespace std;

bool check[100001];
int prev_node[100001];
int ans_arr[100001];
vector<int> vec[100001];
int N, at;
bool fail = false;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int from, to, input;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }

    queue<int> que;
    int cnt = 0;
    int index = 2;

    for (int i = 1; i <= N; i++) {
        cin >> ans_arr[i];
    }

    // bfs start!
    
    fail = false;
    que.push(1);
    check[1] = true;
    prev_node[1] = 1;
    //cnt++;
    
    for(int i = 1; i <= N; i++) {
        if (que.empty()) {
            //cout << "It's empty now! " << '\n';
            fail = true;
            break;
        }

        cnt = 0;
        
        int node_now = que.front();
        que.pop();
        if (ans_arr[i] != node_now) {
            //cout << '\n' << "Second trap is work's" << '\n' 
            //    << i << "번째 숫자는 " << ans_arr[i] << "인데, "<< node_now << "라고 하네" <<'\n';
            fail = true;
            break;
        }
        for (int j = 0; j < vec[node_now].size(); j++) {
            int next_node = vec[node_now][j];
            if (check[next_node] == false) {
                prev_node[next_node] = node_now;
                //cout << next_node << "노드는 " << node_now << "노드로 부터 왔다고 마킹." << '\n';
                cnt++;
            }
        }
        //cout << i << "번째 시행. 현재 index = " << index << ", 현재 cnt = " << cnt << '.' << '\n';
        for (int j = 0; j < cnt; j++) {
            if ( index+j > N || prev_node[ans_arr[index + j]] != node_now) {
                //cout << "검거. " << index + j << "번째 숫자인 " << ans_arr[index + j] << "의 이전 노드는 " << '\n'
                //    << node_now << "가 아닌, " << prev_node[ans_arr[index + j]] << "여야함." << '\n';
                fail = true;
                break;
            }
            else {
                que.push(ans_arr[index + j]);
                check[ans_arr[index + j]] = true;
            }
        }
        index = index + cnt;
        if (fail == true) {
            break;
        }

    }
    if (fail == true) {
        cout << 0;
    }
    else {
        cout << 1;
    }
    
}
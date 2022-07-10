#include<iostream>
#include <string>
#include <stack>
#include <vector>
//#include <algorithm>
//#include <queue>
//#include<cstring>
using namespace std;


pair<int, int> prev_node[51][51];
int N, M;
bool check[51][51];
string s[51];
stack<pair<int, int>> stack_1;
//vector<int> vec[50][50];

// x는 아래가 플러스, y는 오른쪽이 플러스
int x_arr[4] = {-1, 0, 1, 0};
int y_arr[4] = {0, 1, 0, -1};

bool yes = false;

// line에는 0을 넣자.
void dfs(int node_1, int node_2) {

    stack_1.push(make_pair(node_1, node_2));
    int fx = node_1; int fy = node_2;
    //check[fx][fy] = true;
    prev_node[fx][fy] = make_pair(fx, fy);
    // 시작점은 자기 자신을 넣어보자 그러면 어떻게 될까

    while (!stack_1.empty()) {
        int x = stack_1.top().first; int y = stack_1.top().second;
        pair<int, int> now = stack_1.top();
        stack_1.pop();
        check[x][y] = true;
        for (int i = 0 ; i < 4; i++) {
            int new_x = x + x_arr[i]; int new_y = y + y_arr[i];
            if (0 <= new_x && new_x < N && 0 <= new_y && new_y < M) {
                if (s[new_x][new_y] == s[x][y] && check[new_x][new_y] == true 
                    && (prev_node[x][y] != make_pair(new_x, new_y))) {
                    cout << "Yes" << '\n';
                    /*cout << "(new_x, new_y) = (" << new_x << ", " << new_y << ") 이고, " << '\n';
                    cout << "(x, y) = (" << x << ", " << y << ") 이다. " << '\n';
                    cout << "얘네는 " << "(" << prev_node[new_x][new_y].first << ", " << prev_node[new_x][new_y].second << ") 에서 왔다" << '\n';*/
                    yes = true;
                    return;
                }
                else if (s[new_x][new_y] == s[x][y] && check[new_x][new_y] == false) {
                    check[new_x][new_y] = true;
                    prev_node[new_x][new_y] = make_pair(x,y);
                    stack_1.push(make_pair(new_x, new_y));
                }
                
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (check[i][j] == false && yes == false) {
                dfs(i, j);
            }
        }
    }
    if (yes == false) {
        cout << "No";
    }

}
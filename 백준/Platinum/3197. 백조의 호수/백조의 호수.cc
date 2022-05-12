#include<iostream>
#include <string>
#include <stack>
#include <vector>
//#include <algorithm>
#include <queue>
#include<cstring>
using namespace std;

bool all_stop = false;
int day = 1;

int R, C;
string s[1500];
int map[1500][1500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>> water1;
queue<pair<int, int>> water2;
stack<pair<int, int>> swim;
vector<pair<int, int>> bird;
bool check[1500][1500];

// check 배제한 버젼

int dfs(int level) {
    memset(check, false, sizeof(check));
    int start_x = bird[0].first; int start_y = bird[0].second;
    int target_x = bird[1].first; int target_y = bird[1].second;
    swim.push(make_pair(start_x, start_y));
    check[start_x][start_y] = true;
    while (!swim.empty()) {
        int x = swim.top().first; int y = swim.top().second;
        swim.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i]; int new_y = y + dy[i];
            if (0 <= new_x && new_x < R && 0 <= new_y && new_y < C) {
                if (new_x == target_x && new_y == target_y) {
                    while (!swim.empty()) {
                        swim.pop();
                    }
                    return level;
                }
                if (map[new_x][new_y] != -1 && map[new_x][new_y] <= level 
                    && check[new_x][new_y] == false) {
                    check[new_x][new_y] = true;
                    swim.push(make_pair(new_x, new_y));
                }
            }
        }
    }
    return -1;
}

void bfs1() {
    //int num_water = water1.size();
    while (!water1.empty()) {
        int x = water1.front().first; int y = water1.front().second;
        water1.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i]; int new_y = y + dy[i];
            if (0 <= new_x && new_x < R && 0 <= new_y && new_y < C) {
                if (map[new_x][new_y] == -1) {
                    map[new_x][new_y] = day;
                    water2.push(make_pair(new_x, new_y));
                }
            }
        }
    }
    day++;
}
void bfs2() {
    //int num_water = water2.size();
    while (!water2.empty()) {
        int x = water2.front().first; int y = water2.front().second;
        water2.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i]; int new_y = y + dy[i];
            if (0 <= new_x && new_x < R && 0 <= new_y && new_y < C) {
                if (map[new_x][new_y] == -1) {
                    map[new_x][new_y] = day;
                    water1.push(make_pair(new_x, new_y));
                }
            }
        }
    }
    day++;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans2;
    string input;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> s[i];
        for (int j = 0; j < C; j++) {
            if (s[i][j] == '.') {
                water1.push(make_pair(i, j));
                map[i][j] = 0;
            }
            else if (s[i][j] == 'L') {
                bird.push_back(make_pair(i, j));
                water1.push(make_pair(i, j));
                map[i][j] = 0;
            }
            else {
                map[i][j] = -1;
            }
            
        }
    }
    if (bird.size() != 2) {
        cout << 1;
        return 0;
    }
    
    while (1) {
        if (water2.empty() && !water1.empty()) {
            bfs1();
        }
        else if (water1.empty() && !water2.empty()) {
            bfs2();
        }
        else if (water1.empty() && water2.empty()) {
            //cout << "무야호" << day << '\n';
            break;

        }
    }
    /*for (int i = 0; i < R; i++) {
        cout << s[i] << '\n';
    }*/

    int ans = 2250001;
    int start = 0; int last = day;
    while(start<=last){
        int mid = (start + last) / 2;
        int result = dfs(mid);
        if (result != -1) {
            ans = min(ans, result);
            last = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    cout << ans;
    
}
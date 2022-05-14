#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int>> windows;
int T, N, h, w, key_cnt, doc_cnt, doc_lim;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
bool check[101][101][30];
bool keyCheck[27];
bool docCheck[101][101];
char map[101][101];

void bfs() {
    int y_now, x_now, new_y, new_x, phase_now, phase = 0;
    queue<pair<pair<int,int>, int>> que;
    // 동적으로 하기 위해 while로 바꿔야 함
    while(phase <= key_cnt + 1) {
        //for(int phase = 0; phase <= key_cnt; phase++) {
        for(pair<int, int> window : windows) {
            if('A' <= map[window.first][window.second] && map[window.first][window.second] <= 'Z'
               && (!keyCheck[map[window.first][window.second] - 'A']) || check[window.first][window.second][phase]) continue;
            else if('a' <= map[window.first][window.second] && map[window.first][window.second] <= 'z') {
                if(!keyCheck[map[window.first][window.second] - 'a'])key_cnt++;
                keyCheck[map[window.first][window.second] - 'a'] = true;
                map[window.first][window.second] = '.';
            } else if(map[window.first][window.second] == '$') {
                map[window.first][window.second] = '.';
                //docCheck[new_y][new_x] = false;
                doc_cnt++;
                if(doc_lim == doc_cnt) return;
            }
            check[window.first][window.second][phase] = true;
            que.push({{window.first, window.second}, phase});
        }
        while(!que.empty()) {
            y_now = que.front().first.first;
            x_now = que.front().first.second;
            phase_now = que.front().second;
            que.pop();
            //cout << "now : {" << y_now << ", " << x_now << "}  (" << phase_now << ")" << '\n';
            for(int i = 0; i < 4; i++) {
                new_y = y_now + dy[i]; new_x = x_now + dx[i];
                if(0 > new_y || new_y >= h || 0 > new_x || new_x >= w) continue;
                if(map[new_y][new_x] == '*' || check[new_y][new_x][phase_now]) continue;
                if('A' <= map[new_y][new_x] && map[new_y][new_x] <= 'Z' && !keyCheck[map[new_y][new_x] - 'A']) {
                    //cout << "no key " << map[new_y][new_x] - 'A' << '\n';
                    continue;
                }

                // 이제 가능한 부분
                //cout << "push : {" << new_y << ", " << new_x << " (" << phase_now << ")";
                check[new_y][new_x][phase_now] = true;
                if('A' <= map[new_y][new_x] && map[new_y][new_x] <= 'Z') {
                    map[new_y][new_x] = '.';
                }
                else if('a' <= map[new_y][new_x] && map[new_y][new_x] <= 'z') {
                    if(!keyCheck[map[new_y][new_x] - 'a'])key_cnt++;
                    keyCheck[map[new_y][new_x] - 'a'] = true;
                    map[new_y][new_x] = '.';
                    //cout << " new key!";
                } else if(map[new_y][new_x] == '$') {
                    map[new_y][new_x] = '.';
                    //docCheck[new_y][new_x] = false;
                    doc_cnt++;
                    //if(doc_lim == doc_cnt) return;
                    //cout << " new doc!";
                }
                //cout << '\n';
                que.push({{new_y, new_x}, phase_now});
            }
            //cout << '\n';
        }
        phase++;
    }
}

int main() {
    string str;
    cin >> T;
    while (T--) {
        memset(check, false, sizeof(check));
        memset(keyCheck, false, sizeof(keyCheck));
        windows = {};
        //memset(docCheck, false, sizeof(docCheck));
        doc_cnt = doc_lim = key_cnt = 0;
        cin >> h >> w;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && map[i][j] != '*') windows.emplace_back(i, j);
                if (map[i][j] == '$') {
                    //docCheck[i][j] = true;
                    doc_lim++;
                }
            }
        }
        cin >> str;
        if (str[0] != '0') for (char ch: str) keyCheck[ch - 'a'] = true;
        /*for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) cout << map[i][j] << " ";
            cout << '\n';
        }
        for(int i = 0; i < 26; i++) if(keyCheck[i]) cout << "we have key " << i << '\n';*/
        bfs();
        cout << doc_cnt << '\n';
    }
}
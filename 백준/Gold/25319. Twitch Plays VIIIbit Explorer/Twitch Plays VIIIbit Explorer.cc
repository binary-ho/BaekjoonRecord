#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N, M, S, num_now, idx;
int board[50][50], cnt[26];
vector<int> L;
map<int, int> L_map;
vector<pair<int, int>> vec[26];
int main() {

    cin >> N >> M >> S;
    string str, ans = "";
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < M; j++) {
            num_now=  str[j] - 'a';
            board[i][j] =num_now;
            cnt[num_now]++;
            vec[num_now].emplace_back(i, j);
        }
    }
    cin >> str;
    for(char c : str) {
        L_map[c - 'a']++;
    }
    int C = 2501;
    for(int i = 0; i < 26; i++) {
        if(L_map[i] > 0 && C > cnt[i]/L_map[i]) C = cnt[i]/L_map[i];
    }
    if(C==2501) C = 0;
    cout << C << " ";
    int char_now, y_now = 0, x_now = 0, move_y, move_x, dist;
    while(C--) {
        for(char c : str) {
            //cout << c << " ";
            char_now = c-'a';
            // 각 철자별로 위치 찾아서 거기로 찾아가.
            //auto p = vec[char_now][idx[char_now]++];
            dist = 101;
            for(int i=0;i<vec[char_now].size();i++) {
                auto p = vec[char_now][i];
                //cout << "[" << p.first << " " << p.second << "] ";
                if(dist > abs(p.first - y_now) + abs(p.second - x_now)) {
                    dist = abs(p.first - y_now) + abs(p.second - x_now);
                    move_y = p.first - y_now;
                    move_x = p.second - x_now;
                    idx = i;
                    //cout << " -> " << "[" << p.first << " " << p.second << "] ";
                }
            }
            //cout << "move: (" << move_y << ", " << move_x << ") ";
            vec[char_now].erase(vec[char_now].begin() + idx);
            y_now += move_y;
            x_now += move_x;
            if(move_y >= 0) {
                while (move_y > 0) {
                    ans += "D";
                    move_y--;
                }
            } else {
                while (move_y < 0) {
                    ans += "U";
                    move_y++;
                }
            }
            if(move_x >= 0) {
                while (move_x > 0) {
                    ans += "R";
                    move_x--;
                }
            } else {
                while (move_x < 0) {
                    ans += "L";
                    move_x++;
                }
            }
            ans += "P";
            //cout << ans << " " << y_now << " " << x_now << '\n';
        }
    }
    pair<int, int> p = {N-1, M-1};
    move_y = p.first - y_now;
    y_now = p.first;
    move_x = p.second - x_now;
    x_now = p.second;
    if(move_y >= 0) {
        while (move_y > 0) {
            ans += "D";
            move_y--;
        }
    } else {
        while (move_y < 0) {
            ans += "U";
            move_y++;
        }
    }
    if(move_x >= 0) {
        while (move_x > 0) {
            ans += "R";
            move_x--;
        }
    } else {
        while (move_x < 0) {
            ans += "L";
            move_x++;
        }
    }
    cout << ans.size() << '\n' << ans;
}

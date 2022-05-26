#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

char map[100][100];
bool check[100][100];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

using namespace std;

int main() {
    int N, M;
    string input;
    cin >> N >> M;
    vector<pair<int, int>> counting_star;
    for(int i = 0; i < N; i++) {
        cin >> input;
        for(int j = 0; j < M; j++) {
            map[i][j] = input[j];
            if(map[i][j] == '*') {
                counting_star.emplace_back(i, j);
            }
        }
    }
    int cnt_now, star_cnt, y, x, ans = 0;
    vector<tuple<int, int, int>> ans_vec;
    for(pair<int, int> star : counting_star) {
        cnt_now = 100;
        for(int i = 0; i < 4; i++) {
            y = star.first; x = star.second;
            star_cnt = 0;
            while(y < N && y >= 0 && x < M && x >= 0 && map[y][x] == '*') {
                star_cnt++;
                y += dy[i];
                x += dx[i];
            }
            cnt_now = min(cnt_now, star_cnt);
            if(cnt_now == 1) break;
        }
        if(cnt_now == 1) continue;
        ans_vec.emplace_back(make_tuple(star.first + 1, star.second + 1, cnt_now - 1));
        for(int i = 0; i < 4; i++) {
            y = star.first;
            x = star.second;
            for(int j = 0; j < cnt_now; j++) {
                if (!check[y][x]) {
                    check[y][x] = true;
                    ans++;
                }
                y += dy[i];
                x += dx[i];
            }
        }
    }
    if(counting_star.size() == ans) {
        cout << ans_vec.size() << '\n';
        int ans_y, ans_x, ans_size;
        for(tuple<int, int, int> t : ans_vec) {
            tie(ans_y, ans_x, ans_size) = t;
            cout << ans_y << " " << ans_x << " " << ans_size << '\n';
        }
    } else {
        cout << "-1";
    }
}
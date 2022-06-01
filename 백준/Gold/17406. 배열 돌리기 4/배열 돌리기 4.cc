#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, K, ans;
int matrix[51][51], temp_matrix[51][51];
int rotate_arr[200];
vector<pair<pair<int,int>, int>> rotate_vec;

int made_min() {
    int min_row = 5001, temp;
    for(int i = 1; i <= N; i++) {
        temp = 0;
        for(int j = 1; j <= M; j++) {
            temp += temp_matrix[i][j];
        }
        if(min_row > temp) min_row = temp;
    }
    return min_row;
}


void rotate(int r1, int c1, int r2, int c2) {
    int idx = 0;
    for(int c = c1; c <= c2; c++) {
        rotate_arr[idx++] = temp_matrix[r1][c];
    }
    for(int r = r1 + 1; r <= r2; r++) {
        rotate_arr[idx++] = temp_matrix[r][c2];
    }
    for(int c = c2 - 1; c >= c1; c--) {
        rotate_arr[idx++] = temp_matrix[r2][c];
    }
    for(int r = r2 - 1; r > r1; r--) {
        rotate_arr[idx++] = temp_matrix[r][c1];
    }
    int idx2 = 0;
    for(int c = c1+1; c <= c2; c++) {
        temp_matrix[r1][c] = rotate_arr[idx2++];
    }
    for(int r = r1 + 1; r <= r2; r++) {
        temp_matrix[r][c2] = rotate_arr[idx2++];
    }
    for(int c = c2 - 1; c >= c1; c--) {
        temp_matrix[r2][c] = rotate_arr[idx2++];
    }
    for(int r = r2 - 1; r >= r1; r--) {
        temp_matrix[r][c1] = rotate_arr[idx2++];
    }
}

void copy_arr() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            temp_matrix[i][j] = matrix[i][j];
        }
    }
}

void init_rotate(string str) {
    copy_arr();
    int r, c, s, idx_now;
    for(int i = 0; i < str.size(); i++) {
        idx_now = str[i] - '0';
        r = rotate_vec[idx_now].first.first;
        c = rotate_vec[idx_now].first.second;
        s = rotate_vec[idx_now].second;
        for(int ss = 1; ss <= s; ss++) {
            rotate(r - ss, c - ss, r + ss, c + ss);
        }
    }
    int min_mat = made_min();
    if(ans > min_mat) ans = min_mat;
}

void choice(int idx, string str, int check) {
    if(idx == K) {
        init_rotate(str);
        return;
    }
    for(int i = 0; i < K; i++) {
        if((check & (1 << i)) != 0) continue;
        choice(idx+1, str + to_string(i), check | (1<<i));
    }
}

int main() {
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> matrix[i][j];
        }
    }
    int r, c, s;
    for(int i = 0; i < K; i++) {
        cin >> r >> c >> s;
        rotate_vec.push_back({{r,c},s});
    }
    ans = 5001;
    choice(0, "", 0);
    cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, K, ans;
int matrix[301][301], temp_matrix[301][301];
int rotate_arr[90001];
vector<pair<pair<int,int>, int>> rotate_vec;


void rotate2(int r1, int c1, int r2, int c2, int T) {
    int mod;
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
    mod = idx;
    int idx2 = T;
    for(int c = c1; c <= c2; c++) {
        temp_matrix[r1][c] = rotate_arr[idx2%mod];
        idx2++;
    }
    for(int r = r1 + 1; r <= r2; r++) {
        temp_matrix[r][c2] = rotate_arr[idx2%mod];
        idx2++;
    }
    for(int c = c2 - 1; c >= c1; c--) {
        temp_matrix[r2][c] = rotate_arr[idx2%mod];
        idx2++;
    }
    for(int r = r2 - 1; r > r1; r--) {
        temp_matrix[r][c1] = rotate_arr[idx2%mod];
        idx2++;
    }

    /*
    for(int r = r1 + 1; r <= r2; r++) {
        temp_matrix[r][c1] = rotate_arr[idx2++];
    }
    for(int c = c1 + 1; c <= c2; c++) {
        temp_matrix[r2][c] = rotate_arr[idx2++];
    }
    for(int r = r2 - 1; r >= r1; r--) {
        temp_matrix[r][c2] = rotate_arr[idx2++];
    }
    for(int c = c2 - 1; c > c1; c--) {
        temp_matrix[r1][c] = rotate_arr[idx2++];
    }*/
}

void copy_arr() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            temp_matrix[i][j] = matrix[i][j];
        }
    }
}


void init_rotate2(int T) {
    copy_arr();
    int r1=1, r2=N, c1=1,c2=M;
    while((r1 < r2) && (c1 < c2)) {
        rotate2(r1,c1,r2,c2, T);
        r1++;c1++;
        r2--;c2--;
    }
}


int main() {
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> matrix[i][j];
        }
    }
    init_rotate2(K);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++) {
            cout << temp_matrix[i][j] << " ";
        }
        cout << '\n';
    }

}
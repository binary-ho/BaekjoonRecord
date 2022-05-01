#include <iostream>
#include <vector>

using namespace std;

int N, map[21][21];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
vector<int> bf_vec[401];


pair<int, int> check_best(int student) {
    int max_bf = 0, max_zero = 0, bf, zero;
    pair<int, int> p = {N, N};
    
    for(int y = 1; y <= N; y++) {
        for(int x = 1; x <= N; x++) {
            if(map[y][x] != 0) continue;
            bf = zero = 0;
            for(int i = 0; i < 4; i++) {
                int new_y = y + dy[i], new_x = x + dx[i];
                if(new_y < 1 || new_y > N || new_x < 1 || new_x > N) continue;
                if(map[new_y][new_x] == 0) zero++;
                else {
                    for(int j : bf_vec[student]) {
                        if(map[new_y][new_x] == j) {
                            bf++;
                            break;
                        }
                    }
                }
            }
            if(max_bf < bf) {
                max_bf = bf; max_zero = zero; p.first = y; p.second = x;
            } else if (max_bf == bf) {
                if(max_zero < zero) {
                    max_zero = zero; p.first = y; p.second = x;
                } else if (max_zero == zero) {
                    if(p.first  > y) {
                        p.first = y; p.second = x;
                    } else if (p.first== y) {
                        if(p.second> x) {
                            p.second = x;
                        }
                    }
                }
            }
        }
    }
    return p;
}
int main() {

    int N2, student, bf[4];
    pair<int, int> p;
    cin >> N;
    N2 = N * N;
    for(int i = 0; i < N2; i++) {
        cin >> student >> bf[0] >> bf[1] >> bf[2] >> bf[3];
        bf_vec[student] = {bf[0], bf[1], bf[2], bf[3]};
        if(i == 0) {
            map[2][2] = student;
            continue;
        }
        p = check_best(student);
        map[p.first][p.second] = student;
    }

    int ans = 0, temp, arr[5] = {0, 1, 10, 100, 1000};
    for(int y = 1; y <= N; y++) {
        for(int x = 1; x <= N; x++) {
            temp = 0;
            for(int i = 0; i < 4; i++) {
                int new_y = y + dy[i], new_x = x + dx[i];
                if(new_y < 1 || new_y > N || new_x < 1 || new_x > N) continue;
                for(int j : bf_vec[map[y][x]]) {
                    if(map[new_y][new_x] == j) {
                        temp++;
                        break;
                    }
                }
            }
            ans += arr[temp];
        }
    }
    cout << ans << '\n';
}
#include <iostream>

using namespace std;
int N, M, ans, map[100][100], row[100], col[100];


int main() {
    cin >> N >> M;
    ans = 2*N*M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            /*if(row[i] < map[i][j]) row[i] = map[i][j];
            if(col[j] < map[i][j]) col[j] = map[i][j];*/
        }
    }
    int temp;
    for(int i = 0; i < N; i++) {
        temp = 0;
        for(int j = 0; j < M; j++) {
            if(temp < map[i][j]) {
                ans += (map[i][j] - temp);
            }
            temp = map[i][j];
        }
        temp = 0;
        for(int j = M - 1; j >= 0; j--) {
            if(temp < map[i][j]) {
                ans += (map[i][j] - temp);
            }
            temp = map[i][j];
        }
    }
    for(int j = 0; j < M; j++) {
        temp = 0;
        for(int i = 0; i < N; i++) {
            if(temp < map[i][j]) {
                ans += (map[i][j] - temp);
            }
            temp = map[i][j];
        }
        temp = 0;
        for(int i = N - 1; i >= 0; i--) {
            if(temp < map[i][j]) {
                ans += (map[i][j] - temp);
            }
            temp = map[i][j];
        }
    }
    /*cout << ans << '\n';
    for(int i = 0; i < N; i++) {
        ans += 2*row[i];
    }
    cout << ans << '\n';
    for(int j = 0; j < M; j++) {
        ans += 2*col[j];
    }*/

    cout << ans;
    // 각 행별로, 각 열별로 가장 높은 값을 알면 돼.
}
#include <iostream>
#include <vector>

using namespace std;

#define NO {9876543, 9876543, 9876543, 9876543}

int map[111][100];

int block[7] = {2, 1, 2, 2, 4, 4, 4};
// 1, 네모, 역 ㄹ, ㄹ, ㅗ, 역ㄴ, ㄴ
int dy[7][4][4] = {{{0, -1, -2, -3}, {0, 0, 0, 0}, NO, NO},
                   {{0, 0, -1, -1}, NO, NO, NO},
                   {{0, 0, -1, -1}, {0, -1, 0, 1}, NO, NO},
                   {{0, 0, 1, 1}, {0, -1, -1, -2}, NO, NO},
                   {{0, 0, 0, -1}, {0, -1, -2, -1}, {0, 0, 0, 1}, {0, 0, -1, 1}},
                   {{0, 0, 0, -1}, {0, 0, -1, -2}, {0, -1, -1,- 1}, {0, 0, 1, 2}},
                   {{0, 0, 0, -1}, {0, -1, -2, -2}, {0, 0, 0, 1}, {0, 0, -1, -2}}
};
int dx[7][4][4] = {{{0, 0, 0, 0}, {0, 1, 2,3},  NO, NO},
                   {{0, 1, 0, 1}, NO, NO, NO},
                   {{0, 1, 1, 2}, {0, 0, 1, 1}, NO, NO},
                   {{0, 1, 1, 2}, {0, 0, 1, 1}, NO, NO},
                   {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}},
                   {{0, 1, 2, 2}, {0, 1, 0, 0}, {0 ,0 , 1, 2}, {0, 1, 1, 1}},
                   {{0, 1, 2, 0}, {0, 0, 0, 1}, {0, 1, 2, 2}, {0, 1, 1, 1}}
};

int main() {
    int C, P;
    bool pass;
    cin >> C >> P;
    P--;
    vector<int> vec(C, 0);
    for(int i = 0; i < C; i++) {
        cin >> vec[i];
        for(int j = 0; j < vec[i]; j++) {
            map[110- j][i] = 1;
        }
    }
    /*for(int i = 0; i < 100; i++ ) {
        for(int j = 0; j < 100; j++) {
            cout << map[i][j];
        }
        cout<<'\n';
    }*/
    int y, x, y_now, x_now, cnt = 0;
    for(int i = 0; i < C; i++) {
        // 전체가 3칸이고 1개가 있다면 2에서 1 뺸 1 부터 전체는 99
        // 99 에서 vec을 뺸 지점 부터 시작
        y = 110 - vec[i]; x = i;
        for(int j = 0; j < block[P]; j++) {
            pass = true;
            for(int k = 0; k < 4; k++) {
                y_now = y + dy[P][j][k]; x_now = x + dx[P][j][k];
                if(y_now < 0 || y_now >= 111 || x_now < 0 || x_now >= C || map[y_now][x_now] != 0) {  pass = false;break;}
                map[y_now][x_now] = 2;
            }
            if(pass) {
                for(int k = 0; k < 4; k++) {
                    y_now = y + dy[P][j][k]; x_now = x + dx[P][j][k];
                    if(y_now < 0 || y_now >= 111 || x_now < 0 || x_now >= C || map[y_now][x_now] != 2) { continue;}
                    while(y_now < 110 && map[y_now][x_now] != 0) {
                        y_now++;
                        if(map[y_now][x_now] == 0) {
                            pass = false;
                            break;
                        }
                    }
                }
            };
            for(int k = 0; k < 4; k++) {
                y_now = y + dy[P][j][k]; x_now = x + dx[P][j][k];
                if(y_now < 0 || y_now >= 111 || x_now < 0 || x_now >= C || map[y_now][x_now] != 2) { continue;}
                map[y_now][x_now] = 0;
            }
            if(pass) { cnt++;
            }
        }
    }
    cout << cnt;
}

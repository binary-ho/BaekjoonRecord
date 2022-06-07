#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[51][51];

int main() {
    int N, M, cnt = 0;
    cin >> N >> M;
    bool clk = false;
    for(int i = 0; i < N ; i++) {
        for(int  j = 0; j < M; j++) {
            cin >> map[i][j];
            if(!clk && map[i][j] == '-') clk = true;
            else if(clk && map[i][j] != '-') {
                clk = false;
                cnt++;
            }
        }
        if(clk) {
            clk = false;
            cnt++;
        }
    }
    for(int j = 0; j < M; j++) {
        for(int i = 0; i < N; i++) {
            if(!clk && map[i][j] == '|') clk = true;
            else if(clk && map[i][j] != '|') {
                clk = false;
                cnt++;
            }
        }
        if(clk) {
            clk = false;
            cnt++;
        }
    }
    cout << cnt;
}

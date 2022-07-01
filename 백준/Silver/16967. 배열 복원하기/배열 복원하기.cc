#include <iostream>

using namespace std;
int given[601][601];
int original[301][301];
int made[601][601];

int main() {
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    for(int i = 0; i < H + X; i++) {
        for(int j = 0; j < W + Y; j++) {
            cin >> given[i][j];
        }
    }
    // 1, 0 이라면
    // 0, 2 열이 원래의 배열임
    // 0, 1 이라면
    // 0을 포함해서 X개 만큼 원래 배열이고, H-1을 포함해서 X개 만큼 원래 배열임
    // 0을 포함해서 Y개 만큼 원래 배열이고, W-1을 포함해서 Y개 만큼 원래 배열임\
    // 겹친 부분을 해석할 일이 일절 없나?
    /*
    1 2 3 0
    4 6 8 3
    7 12 14 6
    0 7 8 9 */
    // 무조건 정보를 가지고 있겠구나..?
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < W; j++) {
            original[i][j] = given[i][j];
        }
    }
    // H가 3이고 X가 1일 때
    // 0 1 2
    for(int i = H + X - 1; i > H - 1; i--) {
        for(int j = Y; j < W + Y; j++) {
            original[i - X][j - Y] = given[i][j];
        }
    }

    for(int j = 0; j < Y; j++) {
        for(int i = 0; i < H; i++) {
            original[i][j] = given[i][j];
        }
    }

    for(int j = W + Y - 1; j > W - 1; j--) {
        for(int i = X; i < H + X; i++) {
            original[i - X][j - Y] = given[i][j];
        }
    }

    for(int i = 0; i < H + X; i++) {
        for(int j = 0; j < W + Y; j++) {
            if(X <= i && i < H && Y <= j && j < W) {
                original[i][j] = given[i][j] - original[i-X][j-Y];
            }
        }
    }



    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << original[i][j] << " ";
        }
        cout << '\n';
    }
}
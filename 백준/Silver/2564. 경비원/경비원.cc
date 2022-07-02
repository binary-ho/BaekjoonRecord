#include <iostream>
#include <vector>

using namespace std;


int main() {
    int H, W, N, dir, bias;
    cin >> W >> H >> N;
    vector<pair<int,int>> vec;
    for (int i = 0; i <= N; i++) {
        cin >> dir >> bias;
        if(dir == 1) {
            vec.emplace_back(0, bias);
        } else if (dir == 2) {
            vec.emplace_back(H, bias);
        } else if(dir == 3) {
            vec.emplace_back(bias, 0);
        } else {
            vec.emplace_back(bias, W);
        }
    }
    int y = vec[N].first, x = vec[N].second;
    int r, c, ans = 0;
    for(int i = 0; i < N; i++) {
        r = vec[i].first; c = vec[i].second;
        if(abs(y - r) == H) {
            ans += H;
            if(x + c < W) {
                ans += (x+c);
            } else {
                ans += 2*W - x - c;
            }
        } else if (abs(x - c) == W) {
            ans += W;
            if(y + r < H) {
                ans += (y+r);
            } else {
                ans += 2*H - y - r;
            }
        }
        else {
            ans += (abs(y - r) + abs(x - c));
        }
        //cout << ans << '\n';
    }
    cout << ans;
}
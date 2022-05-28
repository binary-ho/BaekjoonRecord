#include <iostream>

using namespace std;
long long ans;
//int dp[2][21][101];
long long dp[21][2][101];
// 스크롤, 다리, idx
string scroll, bridge[2];

// 다음 G들이 어디있는지 미리 알 수 있다는 점 이욧
int main() {
    cin >> scroll >> bridge[0] >> bridge[1];
    // 말단이 움직이는게 좋으니까 말단을 bridge idx로..
    // 이번에 같아 bridge[i][k] == scroll[j] 안 같으면 k만 커지면 되는거 아님?
    // dp[1 - i][j + 1][k + 1] = dp[i][j][k] + 1;
    //

    for(int i = 0; i < scroll.size(); i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < bridge[0].size(); k++) {
                dp[i][j][k + 1] = dp[i][j][k];
                if(bridge[j][k] == scroll[i]) {
                    if(i == 0) {
                        dp[i][j][k + 1] = dp[i][j][k] + 1;
                    } else  {
                        //dp[i][j][k + 1] = dp[i - 1][1 - j][k] + 1;
                        //dp[i][j][k + 1] = max(dp[i - 1][1 - j][k] + 1, dp[i][j][k] + 1);
                        dp[i][j][k+1] += dp[i-1][1-j][k];
                        //dp[i][j][k + 1] = dp[i][j][k] + 1;
                    }
                }
            }
        }
    }
    /*ans = 0;
    long long sum, bridge_now;
    for(int j = 0; j < 2; j++) {
        bridge_now = j;
        sum = 1;
        for(int k = bridge[0].size(), cnt = scroll.size() - 1; k > 0 && cnt >= 0; k-- && cnt--) {
            sum *= dp[cnt][bridge_now][k];
            bridge_now = 1 - bridge_now;
        }
        ans += sum;
    }*/


    /*for(int i = 0; i < scroll.size(); i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k <= bridge[0].size(); k++) {
                cout << dp[i][j][k];
            }
            cout << '\n';
        }
        cout << '\n';
    }*/
    ans = dp[scroll.size()-1][0][bridge[0].size()] + dp[scroll.size()-1][1][bridge[0].size()];

    cout << ans;
}
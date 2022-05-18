#include <iostream>
#include <vector>
#include <algorithm>

int dp[1002][1002];
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++) {
        for(int j = 0; j < s2.size(); j++) {
            if(s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    /*for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }*/

    string ans = "";
    int ii = s1.size();
    int jj = s2.size();
    while(jj >= 1 && ii >= 1) {
        if(dp[ii][jj] == dp[ii][jj-1] + 1) {
            if(s1[ii-1] == s2[jj-1]) {
                ans += s1[ii-1];
                jj--;
                ii--;
            } else {
                ii--;
            }
        } else {
            jj--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << dp[s1.size()][s2.size()] << '\n' << ans;
}
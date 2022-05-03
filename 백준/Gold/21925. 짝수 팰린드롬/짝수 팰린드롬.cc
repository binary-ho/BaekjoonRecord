#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int N, dp[5001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> vec(N + 1, 0);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    bool pass = false;
    int left = 0, right = 1, left2, right2;
    while(right <= N) {
        if (vec[left] == vec[right - 1] && (right - left)%2 == 0) {
            left2 = left;
            right2 = right - 1;
            while (left2 < right2 && vec[left2] == vec[right2]) {
                left2++;
                right2--;
            }
            if (right2 < left2) pass = true;
            else pass = false;
            if (pass) {
                dp[right] = dp[left] + 1;
                left = right;
            } else {
                dp[right] = dp[left];
            }
            right++;
        } else {
            dp[right] = dp[right-1];
            right++;
        }
    }
    int ans = dp[N];
    if(ans == 0 || N != left) ans = -1;
    cout << ans;
    //<< " -> " << N << ", " << left;
}

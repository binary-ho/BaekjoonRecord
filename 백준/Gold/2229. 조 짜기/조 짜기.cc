#include <iostream>
#include <algorithm>

using namespace std;
int N, arr[1001], dp[1001];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int minmin, maxmax;
    for(int i = 0; i < N; i++) {
        //cout << i << ": ";
        minmin = maxmax = arr[i];
        for(int j = i; j > 0; j--) {
            if(minmin > arr[j]) minmin = arr[j];
            if(maxmax < arr[j]) maxmax = arr[j];
            dp[i] = max(dp[j-1] + (maxmax - minmin), dp[i]);
            //cout << dp[i] << " ";
        }
        if(minmin > arr[0]) minmin = arr[0];
        if(maxmax < arr[0]) maxmax = arr[0];
        dp[i] = max(maxmax - minmin, dp[i]);
        //cout << '\n';
    }
    cout << dp[N-1];
}
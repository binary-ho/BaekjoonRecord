#include <iostream>
#include <vector>
#define INF 10000001
using namespace std;
int dp[501][1002];
int N,M,K,cpu,memory,priority;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;
      // 1001은 넘어 갔을 때의 케이스
    // dp[N][pr_now][cpu_now] = mem_now -> dp[N+1][pr_now + item_pr][cpu_now + item_cpu] = mem_now + item_mem;
    // dp[N][p][c] = dp[N-1][p-item_pr][c - item_cpu] + item_mem;

    for(int j = 0; j < 501; j++) for(int k = 0; k < 1002; k++) dp[j][k] = INF;
    // 전에 거를 껐냐 vs 안 껐냐 차이
    for (int i = 0; i < N; i++) {
        cin >> cpu >> memory >> priority;
        if(i == 0) {
            dp[0][0] = 0;
            dp[priority][cpu] = memory;
            continue;
        }
        // 0 0 0
        // 1 4 1
        // 여기에 만족도 2 cpu 4 메모리 2 더할거임
        for (int p = 500; p >= 0; p--) {
            for (int c = 1001; c >= 0; c--) {
                if(dp[p][c] >= INF) continue;
                if(c + cpu <= 1000) {
                    dp[p + priority][c + cpu] = dp[p+priority][c+cpu] >= INF ? dp[p][c] + memory : max(dp[p + priority][c + cpu], dp[p][c] + memory);
                }
                else { dp[p + priority][1001] = dp[p + priority][1001] >= INF ? dp[p][c] + memory : max(dp[p + priority][1001], dp[p][c] + memory); }
                //cout << i << ": " << p << " " << c << " " << dp[p][c] << '\n';
            }
        }
    }
    //cout << '\n';
    int ans = 501;
    for (int p = 0; p < 501; p++) {
        for (int c = 0; c < 1002; c++) {
            if (dp[p][c] >= INF) continue;
            //cout << p << " " << c << " " << dp[p][c] << '\n';
            if(c < M || dp[p][c] < K || ans <= p) continue;
            ans = p;
        }
    }
    if(ans == 501) ans = -1;
    cout << ans;
}

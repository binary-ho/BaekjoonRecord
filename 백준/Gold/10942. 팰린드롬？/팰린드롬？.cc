#include<iostream>

using namespace std;

int arr[2001];
int dp[2001][2001];    // dp인지 아닌지는 가능한데, 검사를 마치고 false인지 아닌지는 모름
// 0 검사 X
// -1, 1 펠린 X, O;

int main(int argc, char** argv)
{
    int test_case, T;
    ios::sync_with_stdio(false);
    cin.tie(0);


    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) dp[i][i] = 1;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        for(int j = 1; j < i; j++) {
            if(arr[j] != arr[i]) {
                dp[j][i] = -1;
                continue;
            }
            if(j + 1 == i) {
                dp[j][i] = 1;
                continue;
            }
            // 일단 같아 바로 다음은?
            if(j + 1 <= N && i - 1 >= 1 && j + 1 <= i - 1) {
                if(dp[j+1][i-1] == 1) dp[j][i] = 1;
                else dp[j][i] = -1;
            }
        }
    }
    int M, S, E;
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> S >> E;
        if(dp[S][E] == 1) printf("1\n");
        else printf("0\n");
    }
}
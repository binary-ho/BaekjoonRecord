#include<iostream>
#include<algorithm>

using namespace std;

int ten_power[] = {1, 10, 100, 1000,10000,100000,1000000,10000000,100000000};
int zero_bias[] = {1, 11, 111, 1111,11111,111111,1111111,11111111,111111111};
int ans[10];
int dp[9];

void sum(int lim, int num) {
    for(int i = 0; i <= lim; i++) ans[i]+=num;
}

void sum(int start, int end, int num) {
    for(int i = start; i <= end; i++) ans[i]+=num;
}

int main() {
    dp[0] = 1;
    for(int i = 1; i <= 8; i++) {
        dp[i] = dp[i-1]*10 + ten_power[i];
    }
    int N;
    cin >> N;
    string str = to_string(N);
    int length = str.size();
    length--;

    int num_now;
    int sum_num = str[length] - '0';
    sum(0, sum_num, 1);
    if(length == 0) ans[0] -= 1;
    for(int i = 1; i <= length; i++) {
        num_now = str[length - i] - '0';
        for(int j = 0; j < num_now; j++) {
            sum(9, dp[i-1]);
             if(i != length || j != 0) ans[j] += ten_power[i];
        }
        if(i == length) ans[0] -= zero_bias[i-1];
        ans[num_now] += sum_num + 1;
        sum_num += num_now * ten_power[i];
    }
    for(int i = 0; i < 10; i++) {
        cout << ans[i] << " ";
    }


    return 0;
}
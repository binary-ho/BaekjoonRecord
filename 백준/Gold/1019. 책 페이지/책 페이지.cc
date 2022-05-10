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
    // 0 포함해서 세어 줌
    dp[0] = 1; // 0은 1 빼줘야해
    dp[1] = dp[0]*10 + 10; // 1~9는 19씩 추가 맨 앞줄 dp[0]만큼을 0에서 빼줘야해
    dp[2] = dp[1]*10 + 100; // dp[] 1 만큼을 0에서 뺴 줘야해
    // 300 111 뺴주면 된다. 계속 도륙내
    for(int i = 1; i <= 8; i++) {
        dp[i] = dp[i-1]*10 + ten_power[i];
    }
    int N;
    cin >> N;
    string str = to_string(N);
    int length = str.size();
    length--;
    //if(length > 0) sum(9, dp[length - 1]);
    // 또 2칸 아래꺼 더하고, 대신에 이번 숫자만
    // 20이라고 쳐 10까지는 모두 1씩 20까지 모두 1씩 또 더하고 2에만 10을 또 더해 10에서 20갈 때 쓴거니까 지금 자릿수를 더하는거야 10의 자리일때는 10
    // 즉 1일때는 ten_power[1]만큼 2에다가 모두 더하는거지
    // 100의자리일 경우 dp[1]인데 랭쓰는 3이네

    // length 보다 한 자릿수 아래를 봐
    int num_now;
    // i가 가르키는 것은 지금 자릿수가 10의 몇 제곱인지, 그리고 도달 수는 더하지 않은 상태


    int sum_num = str[length] - '0';
    sum(0, sum_num, 1);
    if(length == 0) ans[0] -= 1;
    for(int i = 1; i <= length; i++) {
        num_now = str[length - i] - '0';
        //if(num_now == 0) ans[0] += sum_num;
        for(int j = 0; j < num_now; j++) {
            sum(9, dp[i-1]);
             if(i != length || j != 0) ans[j] += ten_power[i];
            //ans[0] += dp[i - 1];
            //ans[0] += i - 1;
        }
        if(i == length) ans[0] -= zero_bias[i-1];
        //ans[0] -= ten_power[i-1];
        //ans[0] += (i-1);
        ans[num_now] += sum_num + 1;
        sum_num += num_now * ten_power[i];
    }
    //ans[0] -= zero_bias[length-1];
    /*for(int i = length; i > 0; i--) {
        num_now =  str[i] - '0';
        for(int j = 0; j  < num_now; j++) {
            sum(9, dp[i-1]);
            if(j == 0) ans[0] -= dp[i-1];
            else {ans[j] += ten_power[i];}
        }
        ans[0]+=dp[i-1];
        ans[num_now]++;
    }
    sum(1, str[length] - '0', 1);*/
    for(int i = 0; i < 10; i++) {
        cout << ans[i] << " ";
    }


    return 0;
}
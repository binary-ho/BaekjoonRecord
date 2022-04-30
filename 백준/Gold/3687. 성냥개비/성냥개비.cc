#include <iostream>
#include <vector>

using namespace std;

int match[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int match1[8] = {0, 1, 1, 2, 2, 2, 6, 8};
int match2[8] {0, 0, 0, 0, 0, 0, 0 ,8};
int match3[8] {0, 0, 0, 0, 0, 2, 0 ,8};
int dp[8] = {0,0,1,7,4};

string max_made(int N) {
    string str;
    int N2 = N/2;
    while (N2--) str += '1';
    if(N % 2 != 0) str[0] = '7';
    return str;
}

int main() {
    int T, N, length;
    cin >> T;
    while(T--) {
        string str_min, str_max;
        cin >> N;
        str_max = max_made(N);
        if(N<=4) {
            str_min = (dp[N] + '0');
            cout << str_min << " " << str_max << '\n';
            continue;
        }
        if(N%7 == 0) {
            length = N/7;
            while(length--) str_min += '8';
            cout << str_min << " " << str_max << '\n';
            continue;
        }
        length = N/7 + 1;
        for(int i = length; i > 0; i--) {
            if(i == length) {
                str_min += (match1[N - (i-1) * 7] + '0');
                N -= match[match1[N - (i-1) * 7]];
                continue;
            }
            if(i != 1) {
                str_min += (match2[N - (i-1) * 7] + '0');
                N -=  match[match2[N - (i-1) * 7]];
                continue;
            }
            str_min += (match3[N - (i-1) * 7] + '0');
            N -=  match[match3[N - (i-1) * 7]];
        }
        cout << str_min << " " << str_max << '\n';
    }
}
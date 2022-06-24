#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int power[10] = {0, 1, 4, 9, 16,25,36,49,64,81};
void getPrimeVector(int N, vector<int> &vec) {
    int N2 = (int) sqrt(N);
    vector<bool> check(N+1, false);
    for(int i = 2; i <= N2; i++) {
        if(check[i]) continue;
        for(int j = i*i; j <= N; j += i) { check[j] = true; }
    }
    for(int i = 2; i <= N; i++) if(!check[i]) vec.emplace_back(i);
}
int main() {
    int N, buffer, temp;
    cin >> N;
    vector<int> vec, ans;
    getPrimeVector(N, vec);
    bool check[1000];
    string str;
    for(int num_now : vec) {
        temp = num_now;
        //cout << num_now << " : ";
        while(temp != 1) {
            if(temp < 1000 && check[temp]) break;
            if(temp < 1000) check[temp] = true;
            str = to_string(temp);
            buffer = 0;
            for(int i = 0; i < str.size(); i++) {
                buffer += power[str[i] - '0'];
            }
            temp = buffer;
            //cout << temp << " ";
        }
        //cout << '\n';
        if(temp == 1) ans.emplace_back(num_now);
        memset(check, false, sizeof(check));
    }
    for(int num : ans) {
        cout << num << '\n';
    }
}
#include <string>
#include <vector>
#include <cmath>
#define N 10000000

using namespace std;
bool prime[N + 1];
bool check[N + 1];
string str;
int ans = 0;

void getNumber(int limit, int checker, int cnt, string temp) {
    if (limit == cnt) {
        int ret = stoi(temp);
        if (ret == 0 || ret == 1) return;
        
        if (!prime[ret] && !check[ret]) {
            check[ret] = true;
            ans++;
        }
        
        return;
    }
    
    for (int i = 0; i < str.size(); i++) {
        if ((checker & (1 << i)) != 0) continue;
        getNumber(limit, checker | (1 << i), cnt + 1, temp + str[i]);
    }
}

int solution(string numbers) {
    int N2 = (int) sqrt(N);
    for (int i = 2; i <= N2; i++) {
        if (prime[i]) continue;
        for (int j = i*i; j <= N; j += i) {
            prime[j] = true;
        }
    }
    
    str = numbers;
    for (int i = 1; i <= numbers.size(); i++) {
        getNumber(i, 0, 0, "");
    }
    
    return ans;
}
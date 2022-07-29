#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
int N;
int main() {
    cin >> N;
    string ans;
    while(N!=0) {
        if(N%(-2) != 0) {
            ans+="1";
            N = (N-1)/(-2); 
        } else {
            ans+="0";
            N /= (-2);
        }
    }
    if(ans.empty()) {
        ans = "0";
    } else reverse(ans.begin(), ans.end());
    cout << ans;
}
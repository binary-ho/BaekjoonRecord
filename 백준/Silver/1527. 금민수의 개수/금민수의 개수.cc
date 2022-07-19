#include <iostream>
using namespace std;
long long A, B, temp;
int ans, A_size, B_size;

void go(string num) {
    if(num.size() > B_size) return;
    else if(A_size <= num.size() && num.size() <= B_size){
        temp = stoll(num);
        if(A <= temp && temp <= B) ans++;
    }
    go(num + "4");
    go(num + "7");
    return;
}
int main() {
    cin >> A >> B;
    string A_str = to_string(A), B_str = to_string(B);
    ans = 0;
    A_size= A_str.size();
    B_size = B_str.size();
    go("");
    cout << ans;
}
#include <string>
#include <iostream>
using namespace std;
int main() {
    bool pass = false;
    int ans = 0;
    string str;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++) {
        if(str[i] != ' ') {
            if(!pass) {
                ans++;
                pass = true;
            }
        } else {
            pass = false;
        }
    }
    cout << ans;
}
#include <iostream>
#include <cstring>

using namespace std;

bool alpha['z' + 1];
int main() {
    int N, cnt = 0;
    cin >> N;
    string str;
    while (N--) {
        cin >> str;
        memset(alpha, false, sizeof(alpha));
        bool pass = true;
        int idx = 0;
        while (idx < str.size()) {
            char charNow = str[idx];
            if (alpha[charNow]) {
                pass = false;
                break;
            }
            alpha[charNow] = true;
            while (idx < str.size() && charNow == str[idx]) idx++;
        }
        if (pass) cnt++;
    }

    cout << cnt;
}


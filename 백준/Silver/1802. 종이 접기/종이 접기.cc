#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string str) {
    if(str.size() <= 1) return true;
    int length = str.size(), mid = (length - 1)/2;
    for(int bias = 1; bias <= mid; bias++) {
        if(str[mid-bias] == str[mid+bias]) return false;
    }
    return check(str.substr(0, mid)) | check(str.substr(mid + 1, mid));
}


int main() {
    int T;
    bool result;
    string str;
    cin >> T;
    while (T--) {
        cin >> str;
        result = check(str);
        if(result) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}

#include <iostream>
#include <vector>

using namespace std;

vector<string> croList = {
        "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
};

int main() {
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < croList.size(); i++) {
        string croNow = croList[i];
        auto itr = str.find(croNow);
        while (itr != string::npos) {
            str.replace(itr, croNow.size(), "/");
            itr = str.find(croNow);
            cnt++;
        }
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '/') continue;
        cnt++;
    }

    cout << cnt;
    return 0;
}


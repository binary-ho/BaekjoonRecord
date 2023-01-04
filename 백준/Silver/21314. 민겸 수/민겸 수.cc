#include <iostream>
#include <vector>

using namespace std;

string getMinNum(string &str) {
    // 끊어주는데..
    string ans, temp;
    int MCounter = 0;
    for (char ch : str) {
        if (ch == 'M') MCounter++;
        if (ch == 'K') {
            if (MCounter > 0) {
                temp = "1";
                while (--MCounter) temp += "0";
                ans += temp;
            }
            ans += "5";
            MCounter = 0;
        }
    }

    if (MCounter > 0) {
        temp = "1";
        while (--MCounter) temp += "0";
        ans += temp;
    }

    return ans;
}


string getMaxNum(string &str) {
    // 끊어주는데..
    string ans, temp;
    int MCounter = 0;
    for (char ch : str) {
        if (ch == 'M') MCounter++;
        if (ch == 'K') {
            temp = "5";
            while(MCounter--) temp += "0";
            ans += temp;
            MCounter = 0;
        }
    }
    if (MCounter > 0) while (MCounter--) ans += "1";

    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << getMaxNum(str) << '\n';
    cout << getMinNum(str) << '\n';
}

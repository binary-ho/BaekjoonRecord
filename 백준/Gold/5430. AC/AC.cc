#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    int T, size;
    string command, buffer, number;
    cin >> T;
    while (T--) {
        stringstream ss;
        vector<int> vec;
        cin >> command >> size >> buffer;
        buffer = buffer.substr(1, buffer.size() - 2);
        ss.str(buffer);
        while (getline(ss, number, ',')) {
            vec.emplace_back(stoi(number));
        }

        int idx[2] = {0, size}, toggle = 0;
        for (int c = 0; c < command.size(); c++) {
            char ch = command[c];
            if (ch == 'R') {
                toggle = 1 - toggle;
            } else {
                idx[toggle] += (-2 * toggle + 1);
            }
        }

        string ans;
        if (idx[0] == idx[1]) {
            ans = "[]";
        } else if (idx[0] > idx[1]) {
            ans = "error";
        } else {
            ans = "[";
            if (toggle == 0) {
                for (int i = idx[0]; i < idx[1]; i++) {
                    ans += to_string(vec[i]) + ",";
                }
            } else {
                for (int i = idx[1] - 1; i >= idx[0]; i--) {
                    ans += to_string(vec[i]) + ",";
                }
            }
            ans[ans.size() - 1] = ']';
        }
        cout << ans << '\n';
    }
}

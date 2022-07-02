#include <iostream>
#include <vector>

using namespace std;


int main() {
    bool num = false;
    int N, code;
    string str;
    cin >> N >> str;
    int cut = N/5;
    vector<int> buffer, ans;
    for(int i = 0; i <= cut; i++) {
        code = 0;
        if(i != cut) {
            for(int j = 0; j < 5; j++) {
                if(str[i + cut*j] == '#') {
                    code |= (1 << j);
                }
            }
        }

        if(code != 0) buffer.emplace_back(code);
        else {
            // 0: 31 17 31
            // 31 X
            // 2: 29 21 23
            // 3: 21 21 31
            // 4: 7 4 31

            // 5: 23 21 29
            // 6: 31 21 29
            // 7: 1 1 31 X

            // 8: 31 21 31
            // 9: 23 21 31
            if(buffer.size() == 0) continue;
            else if(buffer.size() == 1) ans.emplace_back(1);
            else {
                if(buffer[0] == 29) ans.emplace_back(2);
                else if(buffer[0] == 21) ans.emplace_back(3);
                else if(buffer[0] == 7) ans.emplace_back(4);
                else if(buffer[0] == 1) ans.emplace_back(7);
                else if(buffer[0] == 23) {
                    if(buffer[2] == 29) ans.emplace_back(5);
                    else ans.emplace_back(9);
                } else {
                    if(buffer[2] == 29) ans.emplace_back(6);
                    else if(buffer[1] == 17) ans.emplace_back(0);
                    else ans.emplace_back(8);
                }
            }
            buffer.clear();
        }
    }
    for(int number: ans) {
        cout << number;
    }
}
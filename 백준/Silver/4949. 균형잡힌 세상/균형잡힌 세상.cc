#include <iostream>
#include <map>
#include <stack>

using namespace std;

int main() {

    stack<char> st;
    string str;
    bool check;

    while (1) {
        getline(cin, str, '.');
        if (str[0] == 0 || (str[0] == 10 && str[1] == 0)) break;

        check = true;
        st = {};

        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            if (ch != '(' && ch != ')' && ch != '[' && ch != ']') continue;

            if (ch == ')') {
                if (st.empty() || st.top() != '(') {
                    check = false;
                    break;
                }
                st.pop();
            } else if (ch == ']') {
                if (st.empty() || st.top() != '[') {
                    check = false;
                    break;
                }
                st.pop();
            } else {
                st.push(ch);
            }
        }
        if (check && st.empty()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}


#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for (char bracket : s) {
        if (bracket == '(') {
            st.push(bracket);
        } else {
            if (st.empty() || st.top() == ')') {
                return false;
            }
            st.pop();
        }
    }
    
    if (!st.empty()) {
        return false;
    }
    return true;
}
#include <iostream>
#include <algorithm>

using namespace std;
int A_length, B_int, ans, result;
string A, B;

void choice(int idx, int check, string str) {
    if(idx == A_length) {
        if(str[0] == '0') return;
        result = stoi(str);
        if(result < B_int && result > ans) {
            ans = result;
        }
        return;
    }
    for(int i = 0; i < A_length; i++) {
        if((check & (1 << i)) != 0) continue;
        choice(idx+1, check|(1<<i), str + A[i]);
    }
}

int main() {
    // B가 A보다 짧으면 바로 탈락, 같으면 chice, B가 더 길면 역순 정렬
    cin >> A >> B;

    ans = -1;
    A_length = A.size();
    B_int = stoi(B);

    if(A_length > B.size()) {
        cout << ans;
    } else if(A_length < B.size()) {
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        cout << A;
    } else {
        choice(0, 0, "");
        cout << ans;
    }
}
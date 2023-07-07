#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    string A, B, ans = "";
    cin >> A >> B;

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    int idx1 = 0, idx2 = 0;
    int temp, toggle = 0;
    while (idx1 < A.size() && idx2 < B.size()) {
        temp = A[idx1++] - '0' + B[idx2++] - '0' + toggle;
        if (temp >= 10) {
            temp %= 10;
            toggle = 1;
        } else {
            toggle = 0;
        }
        ans += (char) (temp + '0');
    }

    while (idx1 < A.size()) {
        temp = A[idx1++] - '0' + toggle;
        if (temp >= 10) {
            temp %= 10;
            toggle = 1;
        } else {
            toggle = 0;
        }
        ans += (char) (temp + '0');
    }

    while (idx2 < B.size()) {
        temp = B[idx2++] - '0' + toggle;
        if (temp >= 10) {
            temp %= 10;
            toggle = 1;
        } else {
            toggle = 0;
        }
        ans += (char) (temp + '0');
    }

    if (toggle == 1) {
        ans += '1';
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

#include <iostream>
#include <algorithm>

using namespace std;
long long finger, N, temp;
int main() {
    cin >> finger >> N;
    if(finger == 1) {
        cout << N*8;
    } else if (finger == 5) {
        cout << N*8 + 4;
    } else {
        if(N%2 == 0) {
            temp = finger - 1;
        }  else {
            temp = 9 - finger;
        }
        cout << (N/2)*8 + temp;
    }
}
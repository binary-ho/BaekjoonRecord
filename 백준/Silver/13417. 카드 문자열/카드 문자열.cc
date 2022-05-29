#include <iostream>

using namespace std;
char arr[1000];
int main() {
    int N, T;
    string str, ans;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        str = arr[0];
        for(int i = 1; i < N; i++) {
            if(str[0] >= arr[i]) {
                str = arr[i] + str;
            } else {
                str += arr[i];
            }
        }
        cout << str << '\n';
    }
}
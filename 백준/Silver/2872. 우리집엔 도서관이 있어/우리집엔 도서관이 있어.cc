#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    int cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(vec[i] == N) {
            N--;
        } else {
            cnt++;
        }
    }
    cout << cnt;
}

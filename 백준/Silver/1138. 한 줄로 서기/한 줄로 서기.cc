#include <iostream>
using namespace std;
int N, idx, cnt, ans[11];
bool check[11];
int main() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> idx;
        cnt = 0;
        while(idx >= 0) {
            cnt++;
            if(check[cnt]) continue;
            idx--;
        }
        check[cnt] = true;
        ans[cnt] = i;
    }
    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
}
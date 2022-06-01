#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, min_dist, max_dist;

int main() {
    // 최대한 가까운 애들끼리 엮는데, 부호 다르면 그냥 들지마
    cin >> N >> M;
    vector<int> book(N, 0);
    min_dist = 10001;
    max_dist = -10001;
    int book_left = 0;
    for(int i = 0; i < N; i++) {
        cin >> book[i];
        if(min_dist > book[i]) min_dist = book[i];
        if(max_dist < book[i]) max_dist = book[i];
        if(book[i] < 0) book_left++;
    }
    sort(book.begin(), book.end());
    int ans = 0;
    // 일단 어느 쪽이 더 큰지 판단.
    bool far_left = false;
    if(abs(min_dist) > max_dist) far_left = true;

    for(int i = 0; i < book_left; i+=M) {
        ans += -2*book[i];
    }
    //cout << ans << '\n';
    if(far_left) ans -= -book[0];
    for(int i = N - 1 ; i >= book_left; i-=M) {
        ans += 2*book[i];
    }
    //cout << ans << '\n';
    if(!far_left) ans -= book[N-1];
    cout << ans;
}
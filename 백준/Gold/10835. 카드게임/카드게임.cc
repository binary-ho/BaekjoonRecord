#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N, dp[2001][2001];
bool check[2001][2001];
vector<int> left_deck, right_deck;
int go(int idx_left, int idx_right) {
    if(idx_left == N || idx_right == N) return 0;
    if(check[idx_left][idx_right]) return dp[idx_left][idx_right];
    // 버릴 수 있으면 무조건 버림
    if(left_deck[idx_left] > right_deck[idx_right]) {
        dp[idx_left][idx_right] = right_deck[idx_right] + go(idx_left, idx_right + 1);
    } else {
        dp[idx_left][idx_right] = max(go(idx_left + 1, idx_right), go(idx_left + 1, idx_right + 1));
    }
    check[idx_left][idx_right] = true;
    return dp[idx_left][idx_right];
}

int main() {
    cin >> N;
    // 버릴 수 있을 떄는 무조건 버림
    // 못 버릴 때는 왼쪽만 버릴 때랑 동시에 버릴 때로 나뉨
    left_deck = vector<int>(N);
    right_deck = vector<int>(N);
    for(int i = 0; i < N; i++) cin >> left_deck[i];
    for(int i = 0; i < N; i++) cin >> right_deck[i];
    cout << go(0,0);
}
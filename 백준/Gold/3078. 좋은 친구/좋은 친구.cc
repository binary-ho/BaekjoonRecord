#include <iostream>
#include <vector>

using namespace std;
long long cnt[21];

int main() {
    int N, K;
    long long ans = 0;
    string str;
    cin >> N >> K;
    vector<int> vec;
    for(int i = 0; i < N; i++) {
        cin >> str;
        vec.emplace_back(str.size());
        if(i <= K) {
            cnt[str.size()]++;
        }
    }
    for(int i = 1; i < 21; i++) {
        if(cnt[i] == 0) continue;
        ans += cnt[i]*(cnt[i] - 1)/2;
    }
    //cout << ans << '\n';
    int left = 0, right = K;
    while(right < vec.size()) {
        cnt[vec[left]]--;
        right++;
        if(cnt[vec[right]] > 0) ans += cnt[vec[right]];
        cnt[vec[right]]++;
        left++;
    }
    cout << ans;
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int N, K, max_length = 0;
long long length[10001];
long long ans;

int main() {
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> length[i];
        if (max_length < length[i]) { max_length = length[i]; }
    }

    // 기존에 받은 K개로 N개를 만들 수는 없어.
    // K == N 일때 어쩌라는거지 그대로 쓰지 말라고? 뭐 어쩌라고 ㅠ
    long long begin = 1, end = max_length;
    while (begin <= end) {
        long long mid = (begin + end) / 2;
        int cnt = 0;
        for (int i = 0; i < K; i++) {
            if (mid > length[i]) { continue; }
            cnt += (length[i] / mid);
        }
        //cout << "mid가 " << mid << "일때, " << "cnt는 " << cnt <<'\n';
        if (cnt >= N) {
            if (ans < mid) { ans = mid; }
            begin = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << ans;
}

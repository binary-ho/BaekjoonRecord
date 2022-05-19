#include<iostream>
#include<queue>

using namespace std;

int arr[100001];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, num;
    cin >> N >> K;
    // 수, 인덱스
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= K; i++) {
        que.push(arr[i]);
    }
    for (int i = 1; i <= N - K; i++) {
        que.push(arr[i + K]);
        arr[i] = que.top();
        que.pop();
    }
    for (int i = 1; i <= N - K; i++) {
        cout << arr[i] << " ";
    }
    while (!que.empty()) {
        cout << que.top() << " ";
        que.pop();
    }
    return 0;
}
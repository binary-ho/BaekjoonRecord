#include <iostream>
#include <stack>
using namespace std;

int arr[500001];
int main() {
    int N, temp = 0, same = 0;
    long long cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    stack<pair<int, int>> st;
    for (int i = 0; i < N; i++) {
        temp = 0;
        same = 1;
        if (!st.empty()) {
            if (st.top().first <= arr[i]) {
                while (!st.empty() && st.top().first <= arr[i]) {
                    if (st.top().first == arr[i]) same += st.top().second;
                    temp += st.top().second;
                    st.pop();
                }
                cnt += temp;
                if (!st.empty()) cnt++;
            } else cnt++;
        }
        st.push({arr[i], same});
    }
    cout << cnt;
}
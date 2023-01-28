#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long sum[100001];

int main() {

    int N;
    cin >> N;
    vector<pair<int, int>> XA(N);
    for (int i = 0; i < N ; i++) cin >> XA[i].first >> XA[i].second;
    std::sort(XA.begin(), XA.end());

    sum[0] = XA[0].second;
    for (int i = 1; i < N ; i++) sum[i] = sum[i - 1] + XA[i].second;

    int left = 0, right = N - 1, mid, postOffice = XA[0].first;
    long long temp[3], min_diff = 900000000000001;
    while (left <= right) {
        mid = (left + right) / 2;
        temp[0] = sum[mid] - XA[mid].second;
        temp[1] = sum[N - 1] - sum[mid];
        temp[2] = abs(temp[0] - temp[1]);
        if (min_diff > temp[2]) {
            postOffice = XA[mid].first;
            min_diff = temp[2];
        } else if  (min_diff == temp[2]) {
            postOffice = min(postOffice, XA[mid].first);
        }

        if (temp[0] < temp[1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << postOffice;
}

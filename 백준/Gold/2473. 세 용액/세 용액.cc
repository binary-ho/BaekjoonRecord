#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int main() {
    cin >> N;
    vector<long long> vec(N, 0);
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    vector<int> ans(3, 0);
    int second, third;
    long long sum = 3000000000;
    for(int first = 0; first < N - 2; first++) {
        second = first + 1; third = N - 1;
        while(second < third) {
            if(abs(sum) > abs(vec[first] + vec[second] + vec[third])) {
                sum = vec[first] + vec[second] + vec[third];
                ans[0] = first;
                ans[1] = second;
                ans[2] = third;
            }
            if(vec[first] + vec[second] + vec[third] == 0) break;
            else if(vec[first] + vec[second] + vec[third] < 0) {
                second++;
            } else {
                third--;
            }
        }
    }
    cout << vec[ans[0]] << " " << vec[ans[1]] << " " << vec[ans[2]] << '\n';
}
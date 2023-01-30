#include <iostream>
#include <vector>


using namespace std;

int main() {
    int N, honeyMax = 0;
    cin >> N;
    vector<int> vec(N), sumLeftToRight(N, 0), sumRightToLeft(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        if (honeyMax < vec[i]) honeyMax = vec[i];
    }

    sumLeftToRight[0] = vec[0];
    for (int  i = 1; i < N; i++) {
        sumLeftToRight[i] = sumLeftToRight[i - 1] + vec[i];
    }

    int maxArray[3];
    maxArray[2] = sumLeftToRight[N - 1] + honeyMax - vec[0] - vec[N - 1];

    int temp;
    honeyMax = 0;
    for (int i = 1; i < N; i++) {
        temp = sumLeftToRight[N - 1] - sumLeftToRight[i] - vec[i];
        if (honeyMax < temp) honeyMax = temp;
    }
    maxArray[0] = sumLeftToRight[N - 1] - sumLeftToRight[0] + honeyMax;

    sumRightToLeft[N - 1] = vec[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        sumRightToLeft[i] = sumRightToLeft[i + 1] + vec[i];
    }
    honeyMax = 0;
    for (int i = N - 2; i >= 0; i--) {
        temp = sumRightToLeft[0] - sumRightToLeft[i] - vec[i];
        if (honeyMax < temp) honeyMax = temp;
    }
    maxArray[1] = sumRightToLeft[0] - sumRightToLeft[N - 1] + honeyMax;

    int ans = 0;
    for (int num : maxArray) {
        if (ans < num) ans = num;
    }
    cout << ans;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, B, cost, kcal, ans_now;
    cin >> N  >> cost >> B >> kcal;
    ans_now = kcal / cost;
    vector<int> vec(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for(int kcal_now : vec) {
        if(ans_now > (kcal + kcal_now) / (cost + B)) break;
        kcal += kcal_now;
        cost += B;
        ans_now = kcal / cost;
    }
    cout << ans_now << '\n';
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    double N, cnt, ans = 0, temp;
    bool pass;
    cin >> N;
    vector<double> vec(N);
    for(double i = 0; i < N; i++) cin >> vec[i];
    for(double i = 0; i < N; i++) {
        cnt = 0;
        for(double j = i + 1; j < N; j++) {
            pass = true;
            // 계산
            for(double k = i + 1; k < j; k++) {
                // 조건에 안 맞으면
                temp = (vec[j] - vec[i])*(k-i)/(j-i) + vec[i];
                if(vec[k] < temp) continue;
                pass = false;
                break;
            }
            if(pass) cnt++;
        }
        for(double j = i - 1; j >= 0; j--) {
            pass = true;
            for(double k = i - 1; k > j; k--) {
                temp = (vec[j] - vec[i])*(k-i)/(j-i) + vec[i];
                if(vec[k] < temp) continue;
                pass = false;
                break;
            }
            if(pass) cnt++;
        }
        if(ans < cnt) ans = cnt;
    }
    cout << ans;
}
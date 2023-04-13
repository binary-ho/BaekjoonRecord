#include <string>
#include <vector>
#define MAX 1000000000000000000
using namespace std;

long long solution(int n, vector<int> times) {
    long long start = 1, end = MAX;
    long long ans = MAX + 1, mid;
    long long temp;
    // mid 나누기 타임즈 더한게 엔보다 작냐 크냐
    while (start <= end) {
        temp = 0;
        mid = (start + end) / 2;
        for (int time : times) {
            temp += (mid / (long long) time);
            if (temp >= n) {
                // 줄여야
                if (ans > mid) {
                    ans = mid;
                }
                end = mid - 1;
                break;
            }
        }
        
        if (temp < n) {
            start = mid + 1;
        }
    }
    return ans;
}
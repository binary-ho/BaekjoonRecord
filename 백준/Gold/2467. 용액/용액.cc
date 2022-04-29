#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, left, right, solution1, solution2;
    cin >> N;
    left = solution1 = 0;
    right = solution2 = N-1;
    vector<int> vec(N, 0);
    for(int i = 0; i < N; i++)  cin >> vec[i];
    int property = abs(vec[left] + vec[right]);
    while(left < right) {
        if(property > abs(vec[left] + vec[right])) {
            property = abs(vec[left] + vec[right]);
            solution1 = left;
            solution2 = right;
        }
        if(abs(vec[left + 1] + vec[right]) < abs(vec[left] + vec[right - 1])) {
            left++;
        } else {
            right--;
        }
    }
    cout << vec[solution1] << " " << vec[solution2];
}
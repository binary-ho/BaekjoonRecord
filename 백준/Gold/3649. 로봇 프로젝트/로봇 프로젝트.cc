#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while(1) {
        int x, n;
        cin >> x >> n;
        if(cin.eof()) break;
        x *= 10000000;
        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++) cin >> vec[i];
        sort(vec.begin(), vec.end());
        int left = 0, right = n - 1, temp;
        bool find = false;
        while (left < right) {
            temp = vec[left] + vec[right];
            if (temp == x) {
                find = true;
                break;
            } else if (temp < x) {
                left++;
            } else {
                right--;
            }
        }
        // 1 2 8 9
        if (find) {
            cout << "yes " << vec[left] << " " << vec[right] << '\n';
        } else {
            cout << "danger" << '\n';
        }
    }
}
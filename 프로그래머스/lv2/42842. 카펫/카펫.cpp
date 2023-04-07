#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
// nxm 형태겠지
// (2 * n) + (2 * m) + 4;
vector<int> solution(int brown, int yellow) {
    
    int y2 = (int) sqrt(yellow) + 1;
    for (int y = 1; y <= y2; y++) {
        if (yellow % y != 0) continue;
        if ((2*y + 2*(yellow/y) + 4) == brown) {
            vector<int> vec = {y + 2, (yellow/y) + 2};
            sort(vec.begin(), vec.end(), greater<>());
            return vec;
        }
    }
}
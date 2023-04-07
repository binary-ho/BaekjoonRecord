#include <string>
#include <vector>

using namespace std;

// 큰거 중에 큰거, 작은거 중에 큰거

int solution(vector<vector<int>> sizes) {
    int maxMax = 0;
    int minMax = 0;
    int bigger = 0;
    for (vector<int> size : sizes) {
        bigger = size[0] > size[1] ? 0 : 1;
        if (maxMax < size[bigger]) {
            maxMax = size[bigger];
        }
        
        if (minMax < size[1 - bigger]) {
            minMax = size[1 - bigger];
        }
    }
    return maxMax * minMax;
}

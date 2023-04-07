#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cit) {
    sort(cit.begin(), cit.end());
    
    int citSize = cit.size();
    
    int start = 0;
    int end = cit[citSize - 1];
    int h, hCnt, hMax = 0;

    while (start <= end) {
        h = (start + end) / 2;
        auto itr = lower_bound(cit.begin(), cit.end(), h);
        hCnt = cit.end() - itr;
        
        if (h <= hCnt) {
            if (hMax < h) {
                hMax = h;
            }
            start = h + 1;
        } else {
            end = h - 1;
        }
    }
    
    return hMax;
}
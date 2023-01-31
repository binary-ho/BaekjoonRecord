#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    set<int> lostSet;
    set<int> reserveSet;
    
    std::sort(lost.begin(), lost.end());
    std::sort(reserve.begin(), reserve.end());
    
    for (int student : lost) {
        lostSet.insert(student);
    }

    for (int student : reserve) {
        if (lostSet.count(student) != 0) {
            lostSet.erase(student);
            continue;
        }
        reserveSet.insert(student);
    }
    
    for (int student : lostSet) {
        if (student != 1 && reserveSet.count(student - 1) != 0) {
            reserveSet.erase(student - 1);
            lostSet.erase(student);
            continue;
        }
        
        if (student != n && reserveSet.count(student + 1) != 0) {
            reserveSet.erase(student + 1);
            lostSet.erase(student);
            continue;
        }
    }
    
    return n - lostSet.size();
}
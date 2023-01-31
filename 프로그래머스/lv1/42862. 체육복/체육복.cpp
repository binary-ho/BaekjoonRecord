#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    set<int> lostSet;
    set<int> reserveSet;
    
    std::sort(reserve.begin(), reserve.end());
    
    for (int student : lost) {
        lostSet.insert(student);
    }

    for (int student : reserve) {
        if (lostSet.find(student) != lostSet.end()) {
            lostSet.erase(student);
            continue;
        }
        reserveSet.insert(student);
    }
    
    for (int student : lostSet) {
        if (reserveSet.find(student - 1) != reserveSet.end()) {
            reserveSet.erase(student - 1);
            lostSet.erase(student);
            continue;
        }
        
        if (reserveSet.find(student + 1) != reserveSet.end()) {
            reserveSet.erase(student + 1);
            lostSet.erase(student);
            continue;
        }
    }
    
    return n - lostSet.size();
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int limit, ans, gTarget;
vector<int> vec;

void dfs(int idx, int value) {
    if (idx == limit) {
        if (value == gTarget) {
            ans++;
        }
        return;
    }
    
    dfs(idx + 1, value + vec[idx]);
    dfs(idx + 1, value - vec[idx]);
}

int solution(vector<int> numbers, int target) {
    vec.insert(vec.end(), numbers.begin(), numbers.end());
    limit = vec.size();
    gTarget = target;
    dfs(0, 0);
    
    return ans;
}
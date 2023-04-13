#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &vec1, vector<int> &vec2) {
    return vec1[1] < vec2[1];
}

int solution(vector<vector<int>> routes) {
    int ans = 1;
    sort(routes.begin(), routes.end(), cmp);
    int cam = routes[0][1];
    for (int i = 1; i < routes.size(); i++) {
        if (routes[i][0] <= cam) {
            continue;
        }
        
        ans++;
        cam = routes[i][1];
    }

    return ans;
}
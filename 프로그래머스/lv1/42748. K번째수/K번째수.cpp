#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int> vec : commands) {
        vector<int> sorted = vector<int>(array.begin() + vec[0] - 1, array.begin() + vec[1]);
        sort(sorted.begin(), sorted.end());
        answer.push_back(sorted[vec[2] - 1]);
    }
    
    return answer;
}
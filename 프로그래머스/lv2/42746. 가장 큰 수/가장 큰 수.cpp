#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
    string s3 = s1 + s2, s4 = s2 + s1;
    return s3 > s4;
}

string solution(vector<int> numbers) {
    vector<string> strs;
    
    for (int num : numbers) {
        strs.push_back(to_string(num));
    }
    
    sort(strs.begin(), strs.end(), cmp);

    string answer = "";
    
    for (string str : strs) {
        answer += str;
    }
    
    if (answer[0] == '0') {
        return "0";
    }
    
    return answer;
}
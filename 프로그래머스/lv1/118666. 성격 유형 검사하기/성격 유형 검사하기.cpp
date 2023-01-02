#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<char, int> mbti;
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
        for (int i = 0; i < survey.size(); i++) {
        if (choices[i] == 4) continue;
        if (choices[i] < 4) {
            mbti[survey[i][0]] += (4 - choices[i]);
            continue;
        }
        mbti[survey[i][1]] += (choices[i] - 4);
    }
    answer += (mbti['R'] >= mbti['T'] ? 'R' : 'T');
    answer += (mbti['C'] >= mbti['F'] ? 'C' : 'F');
    answer +=  (mbti['J'] >= mbti['M'] ? 'J' : 'M');
    answer += (mbti['A'] >= mbti['N'] ? 'A' : 'N');

    return answer;
}
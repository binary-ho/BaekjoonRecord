#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> student[3] = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    int size[3];
    size[0] = student[0].size();
    size[1] = student[1].size();
    size[2] = student[2].size();
    
    int correct[3] = {0};
    
    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (answers[i] != student[j][i % size[j]]) continue;
            correct[j]++;
        }
    }
    
    vector<int> answer;
    int maxCorrect = 0;
    for (int i = 0; i < 3; i++) {
        if (maxCorrect < correct[i]) {
            maxCorrect = correct[i];
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (maxCorrect == correct[i]) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
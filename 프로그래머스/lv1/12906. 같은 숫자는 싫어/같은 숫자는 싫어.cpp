#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int temp = -1;
    for (int num : arr) {
        if (temp == num) continue;
        temp = num;
        answer.push_back(num);
    }

    return answer;
}
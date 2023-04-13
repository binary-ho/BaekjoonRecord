#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[50001];
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());    
    
    int start = 0, end = people.size() - 1;
    while (start < end) {
        answer++;
        while (people[start] + people[end] > limit) {
            end--;
        }
        check[start++] = check[end--] = true;
    }
    
    for (int i = 0; i < people.size(); i++) {
        if (!check[i]) {
            answer++;
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isDeleted[1000001];

int getNumber(string str) {
    int isMinus = 0;
    if (str[2] == '-') {
        isMinus = 1;
    }

    int ret = 0;
    for (int i = 2 + isMinus; i < str.size(); i++) {
        ret *= 10;
        ret += str[i] - '0';
    }

    if (isMinus == 1) {
        return -ret;
    }

    return ret;
}

vector<int> solution(vector<string> operations) {

    int temp;
    string strNow;
    priority_queue<pair<int, int>> minQue, maxQue;

    for (int i = 0; i < operations.size(); i++) {
        strNow = operations[i];
        if (strNow[0] == 'I') {
            temp = getNumber(strNow);
            minQue.push({-temp, i});
            maxQue.push({temp, i});
        } else if (strNow[2] == '1') {
            while (!maxQue.empty() && isDeleted[maxQue.top().second]) {
                maxQue.pop();
            }

            if (!maxQue.empty()) {
                isDeleted[maxQue.top().second] = true;
                maxQue.pop();
            }
        } else {
            while (!minQue.empty() && isDeleted[minQue.top().second]) {
                minQue.pop();
            }

            if (!minQue.empty()) {
                isDeleted[minQue.top().second] = true;
                minQue.pop();
            }
        }
    }
    
    while (!maxQue.empty() && isDeleted[maxQue.top().second]) {
        maxQue.pop();
    }
    while (!minQue.empty() && isDeleted[minQue.top().second]) {
        minQue.pop();
    }

    vector<int> answer;
    if (maxQue.empty() || minQue.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(maxQue.top().first);
        answer.push_back(-minQue.top().first);
    }
    
    return answer;
}
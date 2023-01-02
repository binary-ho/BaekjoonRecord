#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    // 원형 큐를 생각할까?
    // 전체 합을 먼저 알아야해
    // 전체 합을 세어주는 과정에서 뭔가 알 수 없을까
    long long sum = 0, sum_now = 0;
    vector<int> c_que;
    for (auto q1 : queue1) { c_que.emplace_back(q1); sum += q1; sum_now += q1; }
    for (auto q2 : queue2) { c_que.emplace_back(q2); sum += q2; }
    if (sum % 2 == 1) return -1;
    int p1 = 0, p2 = queue1.size(), cnt = 0;
    while (1) {
        if (sum_now == sum - sum_now) break;
        if (p1 == c_que.size()) p1 = 0;
        if (p2 == c_que.size()) p2 = 0;

        if (sum_now < sum - sum_now) {
            sum_now += c_que[p2];
            p2++;
        } else {
            sum_now -= c_que[p1];
            p1++;
        }
        cnt++;
        if (cnt > c_que.size()*2) {
            cnt = -1;
            break;
        }
    }

    answer = cnt;
    return answer;
}
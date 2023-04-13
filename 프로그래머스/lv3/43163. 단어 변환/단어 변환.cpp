#include <string>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

// long long은 26개가 감당이 된다. 
// 50 * 50 * 10
// 하나만 다른걸 편하게 아는 방법 -> 비트 마스킹
vector<int> vec[51];
bool check[51];
int dist[51];
int solution(string begin, string target, vector<string> words) {
    int start = 0, end = -1, length = words[0].size();
    words.insert(words.begin(), begin);
    
    for (int i = 0; i < words.size(); i++) {
        if (target.compare(words[i]) == 0) {
            end = i;
        }
        
        int cnt;
        for (int j = 0; j < words.size(); j++) {
            if (i == j) continue;
            cnt = 0;
            for (int k = 0; k < length; k++) {
                if (words[i][k] != words[j][k]) {
                    cnt++;
                }
            }
            
            if (cnt == 1) {
                vec[i].emplace_back(j);
                vec[j].emplace_back(i);
            }
        }
    }
    if (end == -1) {
        return 0;
    }
    
    queue<int> que;
    que.push(start);
    for (int i = 0; i < words.size(); i++) dist[i] = INF;
    dist[start] = 0;
    check[start] = true;
    
    int nodeNow, nextNode;
    while (!que.empty()) {
        nodeNow = que.front();
        que.pop();

        for (int i = 0; i < vec[nodeNow].size(); i++) {
            nextNode = vec[nodeNow][i];
            if (check[nextNode]) continue;
            check[nextNode] = true;
            que.push(nextNode);
            dist[nextNode] = min(dist[nextNode], dist[nodeNow] + 1);
        }
    }
    
    return dist[end] == INF ? 0 : dist[end];
}
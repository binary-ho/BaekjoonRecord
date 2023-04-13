#include<vector>
#include<queue>
using namespace std;

int dist[101][101];
int check[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = 987654321;
        }
    }
    queue<pair<int, int>> que;
    que.push({0, 0});
    dist[0][0] = 1;
    pair<int, int> pairNow, nextPair;
    while (!que.empty()) {
        pairNow = que.front();
        que.pop();
        check[pairNow.first][pairNow.second] = true;
        for (int i = 0; i < 4; i++) {
            nextPair.first = pairNow.first + dy[i];
            nextPair.second = pairNow.second + dx[i];
            if (nextPair.first < 0 || nextPair.first >= n
               || nextPair.second < 0 || nextPair.second >= m) continue;
            if (check[nextPair.first][nextPair.second]) continue;
            if (maps[nextPair.first][nextPair.second] == 0) continue;
            check[nextPair.first][nextPair.second] = true;
            dist[nextPair.first][nextPair.second] = 
                min(dist[nextPair.first][nextPair.second], dist[pairNow.first][pairNow.second] + 1);
            que.push({nextPair.first, nextPair.second});
        }
    }
    
    return dist[n - 1][m - 1] == 987654321 ? -1 : dist[n - 1][m - 1];
}
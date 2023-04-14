#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct p {
    int y, x;
    p (int _y, int _x) {
        y = _y;
        x = _x;
    }
};

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
bool check[200][200], map[200][200];
int dist[200][200];

int solution(vector<vector<int>> rectangle, int chX, int chY, int itemX, int itemY) {
    chY *= 2;
    chX *= 2;
    itemX *= 2;
    itemY *= 2;
    int answer = 0;
    int y1, x1, y2, x2;
    queue<p> que;
    for (vector<int> rec : rectangle) {
        x1 = 2 * rec[0];
        y1 = 2 * rec[1];
        x2 = 2 * rec[2];
        y2 = 2 * rec[3];
        
        map[y1][x1] = true;
        check[y1][x1] = true;
        que.push(p(y1, x1));
        int cnt = 0;
        while (!que.empty()) {
            p pNow = que.front();
            que.pop();
            
            for (int i = 0; i < 4; i++) {
                p nextP = p(pNow.y + dy[i], pNow.x + dx[i]);
                if (nextP.y < y1 || nextP.y > y2 || nextP.x < x1 || nextP.x > x2) continue;
                if (check[nextP.y][nextP.x]) continue;
                check[nextP.y][nextP.x] = true;
                map[nextP.y][nextP.x] = true;
                que.push(nextP);
            }

        }
        memset(check, false, sizeof(check));
    }

    for (vector<int> rec : rectangle) {
        x1 = 2 * rec[0];
        y1 = 2 * rec[1];
        x2 = 2 * rec[2];
        y2 = 2 * rec[3];
        
        map[y1 + 1][x1 + 1] = false;
        check[y1 + 1][x1 + 1] = true;
        que.push(p(y1 + 1, x1 + 1));
        while (!que.empty()) {
            p pNow = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                p nextP = p(pNow.y + dy[i], pNow.x + dx[i]);
                if (nextP.y <= y1 || nextP.y >= y2 || nextP.x <= x1 || nextP.x >= x2) continue;
                if (check[nextP.y][nextP.x]) continue;
                check[nextP.y][nextP.x] = true;
                map[nextP.y][nextP.x] = false;
                que.push(nextP);
            }
        }
        memset(check, false, sizeof(check));
    }
    
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            dist[i][j] = 98765432;
        }
    }
    

    dist[chY][chX] = 0;
    check[chY][chX] = true;
    que.push(p(chY, chX));
    while (!que.empty()) {
        p pNow = que.front();
        que.pop();
        if (pNow.y == itemY && pNow.x == itemX) continue;
        for (int i = 0; i < 4; i++) {
            p nextP = p(pNow.y + dy[i], pNow.x + dx[i]);
            if (nextP.y < 0 || nextP.y > 100 || nextP.x < 0 || nextP.x > 100) continue;
            if (!map[nextP.y][nextP.x]) continue;
            if (dist[nextP.y][nextP.x] < dist[pNow.y][pNow.x] + 1) continue;
            dist[nextP.y][nextP.x] = dist[pNow.y][pNow.x] + 1;
            que.push(nextP);
        }
    }
    
    return dist[itemY][itemX] / 2;
}
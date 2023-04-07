#include <string>
#include <vector>

using namespace std;

vector<vector<int>> info;
int ans = 0;

// 갈 수 있는 던전이 없으면 종료
void goDungeon(int point, long long checker, int ret) {
    
    for (int i = 0; i < info.size(); i++) {
        if ((checker & (1 << i)) != 0) continue;
        if (point < info[i][0]) continue;
        goDungeon(point - info[i][1], checker | (1 << i), ret + 1);
    }
    
    if (ans < ret) {
        ans = ret;
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    info = dungeons;
    goDungeon(k, 0, 0);
    return ans;
}
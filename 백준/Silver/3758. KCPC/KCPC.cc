#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int score[101][101], total_score[101], cnt[101], last_summit[101], king;


int main() {
    // 아이디, 문제 번호, 점수 -> 시간순 저장
    // 순위는 나보다 점수 높은 팀의 수 + 1
    // 동점 처리 제출 횟수 적은 팀, 마지막 제출 시간이 더 빠른 팀
    int T, n, k, t, m, i, j, s;
    cin >> T;
    while(T--) {
        // t가 우리팀 아이디
        cin >> n >> k >> t >> m;
        memset(score, 0, sizeof(score));
        memset(total_score, 0, sizeof(total_score));
        memset(cnt, 0, sizeof(cnt));
        memset(last_summit, 0, sizeof(last_summit));

        for(int time = 0; time < m; time++) {
            // 팀 문제번호 점수
            cin >> i >> j >> s;
            last_summit[i] = time;
            cnt[i]++;
            if(score[i][j] < s) {
                total_score[i] -= score[i][j];
                score[i][j] = s;
                total_score[i] += score[i][j];
            }
        }
        int rank = 1;
        for(int team = 1; team <= n; team++) {
            if(team == t) continue;
            if(total_score[team] < total_score[t]) continue;
            if(total_score[team] == total_score[t]) {
                if(cnt[team] > cnt[t]) continue;
                else if(cnt[t] == cnt[team]) {
                    if(last_summit[t] < last_summit[team]) continue;
                }
            }
            rank++;
        }
        cout << rank << '\n';
    }
}
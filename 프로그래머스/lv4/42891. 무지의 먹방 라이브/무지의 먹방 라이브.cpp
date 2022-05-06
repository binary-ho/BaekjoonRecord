#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> foods;

int solution(vector<int> food_times, long long k) {
    int length = food_times.size();
    // n 시간짜리가 몇 개인지 세준다.
    for(int time : food_times) {
        foods[time]++;
    }
    long long tic = 0, rounds = 0;
    // 2짜리가 1개 있다고 치자.
    // 2바퀴 이후에는 얘를 빼줘야해
    for(pair<int, int> p : foods) {
        if(tic == k || length == 0) break;
        if(tic + (p.first - rounds) * length <= k) {
            tic += (p.first - rounds) * length;
            rounds += (p.first - rounds);
            length -= p.second;
            //cout << "time to eat: " << p.first << " x " << p.second << ", tic: " << tic <<" rounds: " << rounds << " length: " << length << '\n';
        } else {
            
            int tok = p.first - 1;
            while(tic + (tok - rounds) * length > k && tok > rounds) {
                tok--;
            }
            tic += (tok - rounds) * length;
            // 사실 이제 부터 몇 라운드인지, 랭스는 어느 정도인지 중요치 않아.
            //cout << "time to eat: " << p.first << " x " << p.second << ", tic: " << tic <<" rounds: " << rounds << " length: " << length << '\n';
            break;
        }
    }

    int time, answer = 0;
    if(length > 0) {
        for (int i = 0; i < food_times.size(); i++) {
            time = food_times[i];
            if (time <= rounds) continue;
            if (tic == k) {
                answer = i + 1;
                break;
            }
            tic++;
        }
    }
    if(answer == 0) answer = -1;
    //cout << answer;
    return answer;
}

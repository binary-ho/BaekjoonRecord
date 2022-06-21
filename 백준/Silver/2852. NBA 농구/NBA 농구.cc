#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, score[4];
pair<int, int> time_sum[3];
int main() {
    cin >> N;
    // time team
    vector<pair<string, int>> vec;
    int team, winner = 0, min;
    string time_str;
    for(int i = 0; i < N; i++) {
        cin >> team >> time_str;
        vec.emplace_back(time_str, team);
    }
    std::sort(vec.begin(), vec.end());
    time_str = "00:00";
    vec.emplace_back("48:00", 3);
    score[3] = 101;
    for(pair<string, int> p : vec) {
        score[p.second]++;
        // 방금 업댓해서 승자가 바뀌었는지 포인트
        if(winner == p.second || score[winner] > score[p.second]) {
            continue;
        }
        // 승자 교체 타임!
        time_sum[winner].first += stoi(p.first.substr(0,2)) - stoi(time_str.substr(0,2));
        min = stoi(p.first.substr(3,2)) - stoi(time_str.substr(3,2));
        //cout << "test " << time_sum[winner].first << " " << min << '\n';
        if(min < 0) {
            min = 60 + min;
            time_sum[winner].first--;
        }
        time_sum[winner].second += min;
        if(time_sum[winner].second >= 60) {
            time_sum[winner].first += time_sum[winner].second/60;
            time_sum[winner].second %= 60;
        }
        //cout << winner << " " << time_sum[winner].first << " " << time_sum[winner].second << '\n';
        time_str = p.first;
        if(score[winner] == score[p.second]) {
            // 승자를 0으로 돌리고 시간 추가
            winner = 0;
        } else {
            // 승자를 반대로 넘기고 시간 추가
            winner = p.second;
        }
    }
    time_sum[1].first += time_sum[1].second / 60;
    time_sum[1].second %= 60;
    time_sum[2].first += time_sum[2].second / 60;
    time_sum[2].second %= 60;

    string str;
    str = to_string(time_sum[1].first);
    if(str.size() < 2) {
        str = "0" + str;
    }
    cout << str << ":";
    str = to_string(time_sum[1].second);
    if(str.size() < 2) {
        str = "0" + str;
    }
    cout << str << "\n";

    str = to_string(time_sum[2].first);
    if(str.size() < 2) {
        str = "0" + str;
    }
    cout << str << ":";
    str = to_string(time_sum[2].second);
    if(str.size() < 2) {
        str = "0" + str;
    }
    cout << str << "\n";
}
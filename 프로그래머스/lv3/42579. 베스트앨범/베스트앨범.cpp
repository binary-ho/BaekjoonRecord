#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 1. 장르별 재생 횟수 높은 장르 우선
// 2. 장르별 가장 많이 재생된 노래 2개
// 3. 재생 횟수 같으면 고유 번호 낮은거 먼저

// 어떤 장르가 가장 많이 재생?
// 장르에 어떤 곡이 있나? 혹은 장르별 탑 투 유지
// 탑 투는 고유번호 + 재생 횟수
vector<int> solution(vector<string> genres, vector<int> plays) {
    
    
    unordered_map<string, int> playCount;
    // 벡터 : 재생 횟수, 고유번호
    unordered_map<string, vector<pair<int, int>>> topTwo;
    
    int play;
    string name;
    for (int num = 0; num < genres.size(); num++) {
        name = genres[num];
        play = plays[num];
        
        playCount[name] += play;
        
        // 만들고 넣고
        // 넣고 정렬
        // 넣고 정렬 팝

        topTwo[name].push_back({-play, num});
        if (topTwo[name].size() != 1) {
            sort(topTwo[name].begin(), topTwo[name].end());
            
            if (topTwo[name].size() != 2) {
                topTwo[name].pop_back();
            }
        }

        
    }
    
    vector<pair<int, string>> bestOrder;
    for (pair<string, int> p : playCount) {
        bestOrder.push_back({-p.second, p.first});
    }
    sort(bestOrder.begin(), bestOrder.end());
    
    vector<int> answer;
    for (pair<int, string> p : bestOrder) {
        for (pair<int, int> song: topTwo[p.second]) {
            answer.push_back(song.second);
        }
    }
    
    return answer;
}
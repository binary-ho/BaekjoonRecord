#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;


// 나를 포함한 같은 색 애들을 싹 빼줬어
// 뭘 또 빼고 싶냐면 나랑 가중치가 같으면서 색이 다른 애들
// 크기 같으면 무조건 세는 애랑
// 크기 같으면서 색도 같은 애만 세는 애가 필요
// 2 2 2 3 3 3 4 4 4
// 답: 0 0 0 3 3 3 6 6 6
// 0 1 2 3 4 5 6 7 8
// 0 1 2 0 1 2 0 1 2
// 3 중간이라쳐
// 거기까지의 누적합 - 나랑 같은 색 거기 위치 까지 그니까 30 31을 빼준거임
int ans_arr[200001];
int sum_arr[200001];
int cnt_arr[200001];
int cnt_arr2[200001];
vector<int> color_idx_vec[200001];
vector<int> color_sum_vec[200001];

int main() {
    int N;
    cin >> N;
    // 크기, 인덱스, 색
    // 크기 색 인덱스로 근간 부터 바꿔볼게
    // vec.second.first랑 second.second
    vector<pair<int, pair<int, int>>> vec(N, make_pair(0, make_pair(0, 0)));
    for(int i = 0; i < N; i++) {
        cin >> vec[i].second.first>> vec[i].first;
        vec[i].second.second = i;
    }
    sort(vec.begin(), vec.end());
    int sum = 0;
    for(int i = 0; i < N; i++) {
        color_idx_vec[vec[i].second.first].emplace_back(i);
        if(!color_sum_vec[vec[i].second.first].empty()) color_sum_vec[vec[i].second.first].emplace_back(color_sum_vec[vec[i].second.first].back() + vec[i].first);
        else color_sum_vec[vec[i].second.first].emplace_back(vec[i].first);
        sum += vec[i].first;
        sum_arr[i] = sum;
        if(i!=0 && vec[i].first == vec[i - 1].first) cnt_arr[i] = cnt_arr[i - 1] + 1;
        if(i!=0 && vec[i].first == vec[i - 1].first && vec[i].second.first == vec[i-1].second.first) cnt_arr2[i] = cnt_arr2[i - 1] + 1;
    }

    for(int i = 0; i < N; i++) {
        auto itr = lower_bound(color_idx_vec[vec[i].second.first].begin(), color_idx_vec[vec[i].second.first].end(), i);
        // 내 인덱스의 위치  - cnt_arr[i]*vec[i].first
        ans_arr[vec[i].second.second] = sum_arr[i] - color_sum_vec[vec[i].second.first][itr - color_idx_vec[vec[i].second.first].begin()] - (cnt_arr[i] - cnt_arr2[i])*vec[i].first;
    }

    /*for(int i = 0;  i < N; i++ ){
        cout << sum_arr[i] << " ";
    }
    cout << '\n';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < color_sum_vec[i].size(); j++) cout << color_sum_vec[i][j] << " ";

        cout << '\n';
    }
    cout << '\n';
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j < color_idx_vec[i].size(); j++) {
            cout << color_idx_vec[i][j] << '\n';
        }
        cout << '\n';
    }
    cout << '\n';*/
    for(int i = 0; i < N; i++) {
        cout << ans_arr[i] << '\n';
    }
}
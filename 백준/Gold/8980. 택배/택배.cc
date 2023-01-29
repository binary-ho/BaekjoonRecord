#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {

    int N, C, M, src, dest, box;
    cin >> N >> C >> M;
    vector<pair<pair<int, int>, int>> destSrcBox;
    for (int i = 0; i < M; i++) {
        cin >> src >> dest >> box;
        destSrcBox.push_back({{dest, src}, box});
    }
    std::sort(destSrcBox.begin(), destSrcBox.end());

    map<int, int> truck;
    int vectorIdx = 0, city = 1, load = 0, sum = 0;
    while (city <= N) {
        if (truck[city] > 0) {
            sum += truck[city];
            load -= truck[city];
            truck[city] = 0;
        }

        while (vectorIdx < M && C - load >= destSrcBox[vectorIdx].second) {
            if (destSrcBox[vectorIdx].first.second >= city) {
                load += destSrcBox[vectorIdx].second;
                truck[destSrcBox[vectorIdx].first.first] += destSrcBox[vectorIdx].second;
            }
            vectorIdx++;
        }

        while (load < C  && vectorIdx < M) {
            if (destSrcBox[vectorIdx].first.second < city) {
                vectorIdx++;
                continue;
            }
            destSrcBox[vectorIdx].second -= C - load;
            truck[destSrcBox[vectorIdx].first.first] += C - load;
            load = C;
        }

        city++;
    }
    cout << sum;
}

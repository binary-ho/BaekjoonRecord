#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int N;
vector<pair<int, int>> gs25;

int getDistance(int i, int j) {
    int xDist = (gs25[i].first - gs25[j].first) * (gs25[i].first - gs25[j].first);
    int yDist = (gs25[i].second - gs25[j].second) * (gs25[i].second - gs25[j].second);
    return xDist + yDist;
}

int main() {
    cin >> N;

    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        gs25.emplace_back(x, y);
    }

    int minLength, ansX, anxY;
    minLength = ansX = anxY = INF;
    int maxLength, maxI, maxJ, distNow;
    for (int i = 0; i < N; i++) {
        maxLength = maxI = maxJ = -1;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            distNow = getDistance(i, j);
            if (maxLength > distNow) continue;
            maxLength = distNow;
            maxI = i; maxJ = j;
        }
        if (maxLength == -1) continue;
        if (minLength < maxLength) continue;
        minLength = maxLength;
        ansX = maxI; anxY = maxJ;

    }
    if (minLength == INF) ansX = 0;
    cout << (double) gs25[ansX].first << " " << (double) gs25[ansX].second;
    return 0;
}


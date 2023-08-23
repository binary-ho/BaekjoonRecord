#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 4개를 고른다
// 2. 2개씩 짝지어 눈사람을 만드는데, 키 차이가 작을 수록 좋다.
// 3. 아래에 더 큰게 가야한다. (중요?)
// 총 600개의 눈덩이가 있다.
class SnowMan {

public:
    long long snow[2];
    long long length;
    SnowMan(long long snow1, long long snow2, long long length) {
        this->snow[0] = snow1;
        this->snow[1] = snow2;
        this->length = length;
    }
};

bool compareSnow(const SnowMan &snowMan1, const SnowMan &snowMan2) {
    return snowMan1.length < snowMan2.length;
}

int main() {

    int N;
    cin >> N;
    vector<long long> snows;
    for (int i = 0; i < N; i++) {
//        cin >> snows[i];
        long long input;
        cin >> input;
        snows.push_back(input);
    }

    sort(snows.begin(), snows.end());

    vector<SnowMan> snowMans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            SnowMan snowMan = SnowMan(i, j, snows[i] + snows[j]);
            snowMans.emplace_back(snowMan);
        }
    }

    sort(snowMans.begin(), snowMans.end(), compareSnow);

    long long result = 1000000001;
    int index = -1;
    while (++index < snowMans.size() - 1) {
        SnowMan snowMan1 = snowMans[index];
        SnowMan snowMan2 = snowMans[index + 1];
        if (snowMan1.snow[0] == snowMan2.snow[0] || snowMan1.snow[0] == snowMan2.snow[1]
            || snowMan1.snow[1] == snowMan2.snow[0] || snowMan1.snow[1] == snowMan2.snow[1]) continue;
        result = min(result, abs(snowMan1.length - snowMan2.length));
    }

    cout << result;
}


// 2 3 5 5 9

// 전체에서 2개 빼고 2개 선택 -> 598C2 -> 200 * 587 -> 대충 12000개
// 다 곱하면 안돼
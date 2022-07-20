#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, temp;
vector<int> ten, notTen;
int main() {
    cin >> N >> M;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp < 10) {
            continue;
        }
        else if(temp == 10) {
            ans++;
        } else if (temp % 10 == 0){
            ten.emplace_back(temp);
        } else {
            notTen.emplace_back(temp);
        }
    }
    sort(ten.begin(), ten.end());
    int piece;
    for(auto num : ten) {
        piece = num/10;
        if(M >= piece - 1) {
            M -= piece - 1;
            ans += piece;
        } else {
            ans += M;
            M = 0;
        }
        if(M==0) break;
    }
    for(auto num : notTen) {
        piece = num/10; // 최대 조각 갯수, 커팅 횟수
        if(M>= piece) {
            M -= piece;
            ans += piece;
        } else {
            ans += M;
            M = 0;
        }
        if(M == 0) break;
    }
    cout << ans << '\n';
}
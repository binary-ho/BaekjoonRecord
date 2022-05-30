#include <iostream>
#include <vector>

using namespace std;
int N;

vector<int> light;
void boom(int idx) {
    light[idx] = 1 - light[idx];
    if(idx + 1 < N) {
        light[idx + 1] = 1 - light[idx + 1];
    }
    if(idx + 2 < N) {
        light[idx + 2] = 1 - light[idx + 2];
    }
}

int main() {
    cin >> N;
    vector<int> note(N, 0);
    light = vector<int>(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> note[i];
    }
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(light[i] != note[i]) {
            boom(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
}
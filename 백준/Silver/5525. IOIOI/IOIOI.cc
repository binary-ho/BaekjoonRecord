#include <iostream>

using namespace std;

int main() {

    int N, M, ans = 0;
    string IO = "I", str;
    cin >> N >> M >> str;

    for (int i = 0; i < N; i++) {
        IO += "OI";
    }

    int idx = 0, idx2;
    while (idx < M) {
        idx2 = 0;

        if (str[idx] != IO[idx2]) {
            idx++;
            continue;
        }

        while (idx2 < IO.size() && idx < M && str[idx] == IO[idx2]) {
            idx++;
            idx2++;
        }

        if (idx2 == IO.size()) {
            ans++;
            while (idx + 1 < M) {
                if (str[idx] != 'O' || str[idx + 1] != 'I') break;
                ans++;
                idx += 2;
            }
        }
    }
    cout << ans;
}

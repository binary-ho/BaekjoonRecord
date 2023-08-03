#include <iostream>
#include <vector>

using namespace std;

int S, P;
int underStandard;
int password[91];
int standard[91];

int main() {
    // 0면 깎음
    cin >> S >> P;
    string str;
    cin >> str;

    // A, C, G, T
    cin >> standard['A'];
    if (standard['A'] != 0) underStandard++;

    cin >> standard['C'];
    if (standard['C'] != 0) underStandard++;

    cin >> standard['G'];
    if (standard['G'] != 0) underStandard++;

    cin >> standard['T'];
    if (standard['T'] != 0) underStandard++;

    // 0이 아닌데 0이 되거나,
    // 0인데 0이 아니게 되거나
    for (int i = 0; i < P; i++) {
        if (++password[str[i]] == standard[str[i]]) {
            underStandard--;
        }
    }

    int ans = 0;

    if (underStandard == 0) {
        ans++;
    }

    int left = 0, right = P - 1;
    char charTemp;
    while (right < S - 1) {
        charTemp = str[left++];
        if (password[charTemp]-- == standard[charTemp]) {
            underStandard++;
        }

        charTemp = str[++right];
        if (++password[charTemp] == standard[charTemp]) {
            underStandard--;
        }

        if (underStandard == 0) {
            ans++;
        }
    }

    cout << ans;
}

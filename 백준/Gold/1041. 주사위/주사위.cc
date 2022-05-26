#include <iostream>

using namespace std;
long long N, dice[6];
long long min_plane[4];
void dice_sum(int dice_num, int a, int b) {
    if(min_plane[dice_num] > dice[a] + dice[b]) {
        min_plane[dice_num] = dice[a] + dice[b];
    }
}
void dice_sum(int dice_num, int a, int b, int c) {
    if(min_plane[dice_num] > dice[a] + dice[b] + dice[c]) {
        min_plane[dice_num] = dice[a] + dice[b] + dice[c];
    }
}
int main() {
    cin >> N;
    min_plane[1] = min_plane[2] = min_plane[3] = 1000001;
    min_plane[0] = 0;
    long long sum = 0;
    for(int i = 0; i < 6; i++) {
        cin >> dice[i];
        if(min_plane[1] > dice[i]) min_plane[1] = dice[i];
        if(min_plane[0] < dice[i]) min_plane[0] = dice[i];
        sum += dice[i];
    }
    if(N == 1) {
        cout << sum - min_plane[0];
        return 0;
    }
    // 2면
    // ab, ac, ad, ae / bf, cf, df, fe / bc, ce, de, bd
    // 01, 02, 03, 04 / 15, 25, 35, 45 / 12, 24, 34, 13
    dice_sum(2, 0, 1);
    dice_sum(2, 0, 2);
    dice_sum(2, 0, 3);
    dice_sum(2, 0, 4);

    dice_sum(2, 1, 5);
    dice_sum(2, 2, 5);
    dice_sum(2, 3, 5);
    dice_sum(2, 4, 5);

    dice_sum(2, 1, 2);
    dice_sum(2, 2, 4);
    dice_sum(2, 3, 4);
    dice_sum(2, 1, 3);
    // 3면
    // abc, ace, ade, abd / bcf, cef, def, bdf
    // 012, 024, 034, 013 / 125, 245, 345, 135
    dice_sum(3, 0, 1, 2);
    dice_sum(3, 0, 2, 4);
    dice_sum(3, 0, 3, 4);
    dice_sum(3, 0, 1, 3);

    dice_sum(3, 5, 1, 2);
    dice_sum(3, 5, 2, 4);
    dice_sum(3, 5, 3, 4);
    dice_sum(3, 5, 1, 3);

    sum = 0;
    sum += (N - 2)*(5*N - 6)*min_plane[1];
    sum += (8*N - 12)*min_plane[2];
    sum += 4*min_plane[3];

    //cout << min_plane[1] << " " << min_plane[2] << " " << min_plane[3] << "\n";
    //cout << (N - 2)*(5*N - 6)*min_plane[1] << " " << (8*N - 12)*min_plane[2] <<  " " << 4*min_plane[3] << '\n';

    cout << sum;
}
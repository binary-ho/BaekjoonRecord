#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_gcd(int R, int G) {
    if(G == 0) return R;
    return get_gcd(G, R%G);
}
int main() {
    int R, G, gcd;
    cin >> R >> G;

    if(R == G) gcd = R;
    else if(R > G) gcd = get_gcd(R, G);
    else gcd = get_gcd(G, R);

    for(int i = 1; i <= gcd; i++) {
        if(gcd%i != 0) continue;
        cout << i << " " <<  R/i << " " << G/i << '\n';
    }
}

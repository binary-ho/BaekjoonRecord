#include <iostream>
#include <algorithm>

using namespace std;
int N;
int main() {
    cin >> N;
    int a, b, x;
    while(N--) {
        cin >> a >> b;
        for(x = b/a + 1; x >= 1; x--) {
            if(b < a*x) continue;
            else if(b == a*x) break;
            else {
                //cout << x+1  << " ";
                a = a*(x+1) - b;
                b = b*(x+1);
                x = b/a + 1;
            }
        }
        cout << x << '\n';
    }
}
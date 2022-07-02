#include <iostream>
#include <vector>

using namespace std;


int main() {
    int T = 4, x1, y1, p1, q1, x2, y2, p2, q2;
    int W, H;
    // 안 만남 -1, 접함 0, 겹침 1
    while(T--) {
        cin >> x1 >> y1 >> p1 >> q1;
        cin >> x2 >> y2 >> p2 >> q2;
        if(x2 < x1) {
            swap(x1, x2);
            swap(p1, p2);
        }
        if(p1 < x2) {
            W = -1;
        } else if (p1 == x2) {
            W = 0;
        } else {
            W = 1;
        }

        if(y2 < y1) {
            swap(y1, y2);
            swap(q1, q2);
        }
        if(q1 < y2) {
            H = -1;
        } else if (q1 == y2) {
            H = 0;
        } else {
            H = 1;
        }

        if(W == 0 && H == 0) {
            cout << 'c' << '\n';
        } else if(W == 1 && H == 1) {
            cout << 'a' << '\n';
        } else if(W == -1 || H == -1) {
            cout << 'd' << '\n';
        } else {
            cout << 'b' << '\n';
        }
        // X -1 0 1
        // -1 d d d
        // 0 d c b
        // 1 d b a
    }
}
#include <iostream>
#include <vector>

using namespace std;

int x[2],y[2],X[2],Y[2];

int main() {
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    cin >> X[0] >> Y[0] >> X[1] >> Y[1];
    // -1 nope, 0 -> point, 1 -> overlap
    int x_overlap = 1, y_overlap = 1;
    if(x[1] < X[0] || x[0] > X[1]) x_overlap = -1;
    else if(x[1] == X[0] || x[0] == X[1]) x_overlap = 0;

    if(y[1] < Y[0] || y[0] > Y[1]) y_overlap = -1;
    else if(y[1] == Y[0] || y[0] == Y[1]) y_overlap = 0;

    if(x_overlap == 0 && y_overlap == 0) cout << "POINT";
    else if(x_overlap + y_overlap == 1) cout << "LINE";
    else if(x_overlap + y_overlap == 2) cout << "FACE";
    else cout << "NULL";
}

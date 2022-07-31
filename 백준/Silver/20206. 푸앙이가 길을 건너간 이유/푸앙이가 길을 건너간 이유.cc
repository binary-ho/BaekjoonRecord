#include <iostream>
using namespace std;
int A, B, C;
int X1, X2, Y1, Y2;

int main() {
    cin >> A >> B >> C;
    //  0 = Ax + By + C
    // -(Ax+C)/B = y
    cin >> X1 >> X2 >> Y1 >> Y2;
    double ret1, ret2;
    ret1 = -(double)(A*X1+C)/B - (double) Y1;
    ret2 = -(double)(A*X2+C)/B - (double) Y2;
    if(ret1*ret2 < 0) {
        cout << "Poor";
        return 0;
    }
    ret1 = -(double)(A*X1+C)/B - (double) Y2;
    ret2 = -(double)(A*X2+C)/B - (double) Y1;
    if(ret1*ret2 < 0) {
        cout << "Poor";
        return 0;
    }
    cout << "Lucky";
}
#include <iostream>
#include <vector>
#include <algorithm>

#define TIC 100000000

using namespace std;
/*
O(N)
O(N^2)
O(N^3)
O(2^N)
O(N!)
 */
int main() {
    string str;
    int C;
    long long N, T, L;
    cin >> C;
    while (C--) {
        bool pass = false;
        cin >> str >> N >> T >> L;
        if(str == "O(N)") {
            if (N * T <= L * TIC) pass = true;
        }
        else if (str == "O(N^2)") {
            if (N * N * T <= L * TIC) pass = true;
        }
        else if (str == "O(N^3)") {
            if (N * N * N <=(double)L * TIC/T) pass = true;
            //cout << N *N*N*T << '\n';
        }
        else if (str == "O(2^N)") {
            pass = true;
            while(N > 0 && T <= L*TIC) {
                T*=2;
                N--;
            }
            if(N != 0 || T > L*TIC) pass = false;
        }
        else {
            pass = true;
            while(N > 0 && T <= L*TIC) {
                T*=N;
                N--;
            }
            if(N != 0 || T > L*TIC) pass = false;
        }


        if(pass) cout << "May Pass." << '\n';
        else cout << "TLE!" << '\n';
    }
}

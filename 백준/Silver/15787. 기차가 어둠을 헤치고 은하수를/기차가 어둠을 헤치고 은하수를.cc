#include <iostream>
#include <set>

using namespace std;

// 1 ~ N
int N, M;
int train[100001];

int main() {
    cin >> N >> M;

    int cleanBit = (1 << 21) - 2;
    for (int i = 0; i < M; i++) {
        int command, trainNumber, seatNumber;
        cin >> command >> trainNumber;

        if (command == 1) {
            cin >> seatNumber;
            train[trainNumber] |= (1 << seatNumber);
        } else if (command == 2) {
            cin >> seatNumber;
            train[trainNumber] &= ~(1 << seatNumber);
        } else if (command == 3) {
            train[trainNumber] <<= 1;
        } else {
            train[trainNumber] >>= 1;
        }
        
        train[trainNumber] &= cleanBit;
    }

    set<int> st;
    for (int i = 1; i <= N; i++) {
        st.insert(train[i] & cleanBit);
    }
    cout << st.size();
}

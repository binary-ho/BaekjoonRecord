#include <iostream>
#include <queue>

using namespace std;

int main() {

    int T, K;
    long long sum, size;
    cin >> T;
    priority_queue<long long> priorityQueue;
    while (T--) {
        cin >> K;
        while (K--) {
            cin >> size;
            priorityQueue.push(-size);
        }
        sum = 0;
        while(priorityQueue.size() > 1) {
            size = -priorityQueue.top();
            priorityQueue.pop();
            size += -priorityQueue.top();
            priorityQueue.pop();

            sum += size;
            priorityQueue.push(-size);
        }
        priorityQueue.pop();
        cout << sum << '\n';
    }
}

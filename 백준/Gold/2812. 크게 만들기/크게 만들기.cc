#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next, *prev;
};

Node nodePool[500002];

int main() {

    int N, K;
    cin >> N >> K;
    string input;
    cin >> input;

    nodePool[0].value = input[0] - '0';
    nodePool[0].next = &nodePool[1];
    nodePool[0].prev = nullptr;

    for (int i = 1; i < N; i++) {
        nodePool[i].value = input[i] - '0';
        nodePool[i].next = &nodePool[i + 1];
        nodePool[i].prev = &nodePool[i - 1];
    }
    nodePool[N - 1].next = nullptr;

    Node *ptr = &nodePool[0];

    while (0 < K) {
        if (ptr->next == nullptr) {
            ptr = ptr->prev;
            ptr->next = nullptr;
            K--;
            continue;
        }

        if (ptr->value < ptr->next->value) {
            K--;
            if (ptr->prev != nullptr) {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                ptr = ptr->prev;
                continue;
            }
            ptr->next->prev = nullptr;
        }
        ptr = ptr->next;
    }
    while (ptr->prev != nullptr) {
        ptr = ptr->prev;
    }
    while (true) {
        cout << ptr->value;
        if (ptr->next == nullptr) return 0;
        ptr = ptr->next;
    }
}

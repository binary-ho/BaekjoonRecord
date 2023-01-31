#include <string>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node *next, *prev;
};

Node nodePool[1000002];

string solution(string number, int k) {
    
    nodePool[0].value = number[0] - '0';    
    nodePool[0].next = &nodePool[1];
    nodePool[0].prev = nullptr;

    for (int i = 1; i < number.size(); i++) {
        nodePool[i].value = number[i] - '0';
        nodePool[i].next = &nodePool[i + 1];
        nodePool[i].prev = &nodePool[i - 1];
    }
    nodePool[number.size() - 1].next = nullptr;

    Node *ptr = &nodePool[0];

    while (0 < k) {
        if (ptr->next == nullptr) {
            ptr = ptr->prev;
            ptr->next = nullptr;
            k--;
            continue;
        }

        if (ptr->value < ptr->next->value) {
            k--;
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
    
    string answer;
    while (true) {
        answer += ptr->value + '0';
        if (ptr->next == nullptr) return answer;
        ptr = ptr->next;
    }
}

#include<iostream>

using namespace std;

struct Node {
    int value;
    Node *parent, *child[2];
    Node() {
        value = -1;
        parent = child[0] = child[1] = nullptr;
    }
} node_pool[100001];
int pool_cnt;

struct Heap {
    Node *root;
    int size;
    void init() {
        root = nullptr;
        size = pool_cnt = 0;
    }

    Node* get_node(int value) {
        Node *node_now = &node_pool[pool_cnt++];
        node_now->value = value;
        return node_now;
    }

    Node* find_node(int idx) {
        if(idx == 1) return root;
        return find_node(idx >> 1)->child[idx & 1];
    }

    void push(int value) {
        // 최대 크기 벗어나면 고장
        Node* node = get_node(value);
        if(size == 0) {
            size++;
            root = node;
        } else {
            size++;
            Node *parent = find_node(size >> 1);
            parent->child[size & 1] = node;
            node->parent = parent;
            while(node != root && node->parent->value < node->value) {
                swap(node->parent->value, node->value);
                node = node->parent;
            }
        }
    }

    int pop() {
        if(size <= 0) {
            return 0;
        } else if(size == 1) {
            size--;
            return root->value;
        }
        int ans = root->value;
        Node *node = find_node(size);
        root->value = node->value;
        node->parent->child[size & 1] = nullptr;
        size--;
        node = root;
        Node *child;
        while(node->child[0] != nullptr) {
            if(node->child[1] == nullptr) {
                child = node->child[0];
            } else {
                child = node->child[0]->value < node->child[1]->value ? node->child[1] : node->child[0];
            }
            if(node->value > child->value) break;
            swap(node->value, child->value);
            node = child;
        }
        return ans;
    }
};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, cmd;
    cin >> N;
    Heap heap;
    heap.init();
    while(N--) {
        cin >> cmd;
        if(cmd == 0) {
            cout << heap.pop() << '\n';
        } else {
            heap.push(cmd);
        }
    }
    return 0;
}
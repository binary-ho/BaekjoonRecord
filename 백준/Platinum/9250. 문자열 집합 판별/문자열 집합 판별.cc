#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<set>
#include <algorithm>
#include <queue>

#define C_SIZE 26
using namespace std;

int toNum(char c) { return c - 'a'; }
char str_arr[10001];
string str;

struct TrieNode
{
    bool terminal = false;
    TrieNode* fail;
    TrieNode* children[C_SIZE];

    TrieNode() {
        terminal = false;
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (int i = 0; i < C_SIZE; i++) if(children[i]) delete children[i];
    }

    void insert(const char* key) {
        if (*key == 0) terminal = true;
        else {
            int next = toNum(*key);
            if (children[next] == nullptr) {
                children[next] = new TrieNode();
            }
            children[next]->insert(key + 1);
        }
    }
};

void trieBfs(TrieNode *root) {
    root->fail = root;

    queue<TrieNode*> que;
    que.push(root);
    while(!que.empty()) {
        TrieNode *node_now = que.front();
        que.pop();
        for(int ch = 0; ch < C_SIZE; ch++) {
            TrieNode *next_node = node_now->children[ch];
            if(next_node == nullptr) continue;
            if(node_now == root) next_node->fail = root;
            else {
                TrieNode *ptr = node_now->fail;
                while(ptr != root && ptr->children[ch] == nullptr) ptr = ptr->fail;
                if(ptr->children[ch]) ptr = ptr->children[ch];
                next_node->fail = ptr;
            }
            if(next_node->fail->terminal) next_node->terminal = true;
            que.push(next_node);
        }
    }
}

bool ahoCorasick(const string &str, TrieNode *root) {
    vector<pair<int, int>> vec;
    TrieNode *state = root;
    for(int i = 0; i < str.size(); i++) {
        int ch = toNum(str[i]);
        while(state != root && state->children[ch] == nullptr) {
            state = state->fail;
        }
        if(state->children[ch]) state = state->children[ch];
        if(state->terminal) return true;
    }
    return false;
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N;
    TrieNode root;
    register int i = 0;
    for(i = 0; i < N; i++) {
        cin >> str_arr;
        root.insert(str_arr);
    }
    trieBfs(&root);
    cin >> Q;
    for(i = 0; i < Q; i++) {
        cin >> str;
        if(ahoCorasick(str, &root)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
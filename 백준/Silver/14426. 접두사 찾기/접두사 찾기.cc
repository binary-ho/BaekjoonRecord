#include <iostream>
using namespace std;
int N, M;
string str;
struct trie_node {
    trie_node* child[26];
    bool terminal;

    trie_node() {
        for(int i = 0; i < 26; i++) child[i] = NULL;
        terminal = false;
    }

    void insert_str(int idx) {
        if(idx == str.size()) {
            terminal = true;
            return;
        }
        int ch = str[idx] - 'a';
        if(!child[ch]) {
            child[ch] = new trie_node();
        }
        child[ch]->insert_str(idx + 1);
        return;
    }

    bool find_str(int idx) {
        if(idx == str.size()) {
            return true;
        }
        int ch = str[idx] - 'a';
        if(!child[ch]) return false;
        else {
            return child[ch]->find_str(idx+1);
        }
    }
} root;

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> str;
        root.insert_str(0);
    }
    int ans = 0;
    for(int j = 0; j < M ;j++) {
        cin >> str;
        if(root.find_str(0)) ans++;
    }
    cout << ans;
}
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;


struct StringTrieNode {
    map<string, StringTrieNode> children;
} root;

void dfs(StringTrieNode *node_now, int depth) {
    for(pair<string, StringTrieNode> p : node_now->children) {
        for(int i = 0; i < depth; i++) cout << "--";
        cout << p.first << '\n';
        dfs(&p.second, depth + 1);
    }
}
void insert_str(StringTrieNode &node_now, vector<string> &vec, int idx) {
    if(vec.size() == idx) return;
    if(node_now.children.find(vec[idx]) == node_now.children.end()) {
        StringTrieNode *node = new StringTrieNode();
        node_now.children.insert({vec[idx], *node});
    }
    insert_str(node_now.children.find(vec[idx])->second, vec, idx + 1);
}

int main() {
    int N, K;
    cin >> N;
    string str;
    for(int i = 0; i < N; i++) {
        cin >> K;
        vector<string> str_vec(K, "");
        for(int i = 0; i < K; i++) cin >> str_vec[i];
        insert_str(root, str_vec, 0);
    }
    dfs(&root, 0);
}
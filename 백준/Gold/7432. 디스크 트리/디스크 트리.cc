#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include <map>

using namespace std;


struct TrieNode {
    map<string, TrieNode*> children;

    TrieNode() {
        children = {};
    }

    void insertStr(string str) {
        int idx = str.size();
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == 92) { idx = i; break;}
        }
        string next = str.substr(0, idx);
        if(!children[next]) {
            children[next] = new TrieNode;
        }
        if(idx + 1 <= str.size()) children[next]->insertStr(str.substr(idx + 1));
    }
};

void dfs(TrieNode *node_now, int depth) {
    for(pair<string, TrieNode*> p : node_now->children) {
        for(int i = 0; i < depth; i++) cout << " ";
        cout << p.first << '\n';
        if(p.second) dfs(p.second, depth + 1);
    }
}

int main() {
    int N;
    string str;
    TrieNode root;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> str;
        root.insertStr(str);
    }

    dfs(&root, 0);
    return 0;
}
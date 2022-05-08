#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include <map>

#define C_SIZE 26
using namespace std;

int toNum(char c) { return c - 'a'; }
map<string, int> dictionary;

int keyCnt;
struct TrieNode
{
    int keyNum = -1;
    TrieNode* fail;
    TrieNode* children[C_SIZE];

    TrieNode() {
        keyNum = -1;
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (int i = 0; i < C_SIZE; i++) if(children[i]) delete children[i];
    }

    void insert(const char* key, int idx, bool isPrint) {
        if (key[idx] == 0) {
            if(keyNum == -1) {
                keyNum = keyCnt++;
                    dictionary[key]++;
                if(!isPrint) cout << key << '\n';
            } else {
                dictionary[key]++;
                cout << key << to_string(dictionary[key]) << '\n';
            }
        }
        else {
            int next = toNum(key[idx]);
            if (children[next] == nullptr) {
                children[next] = new TrieNode();
                if(!isPrint) {
                    for(int i = 0; i <= idx; i++) {
                        cout << key[i];
                    }
                    cout << '\n';
                    isPrint = true;
                }
            }
            children[next]->insert(key, idx+1, isPrint);
        }
    }
};



int main() {
    int N;
    char nickname[11];
    keyCnt = 0;
    cin >> N;
    TrieNode trie;
    for(int i = 0; i < N; i++) {
        scanf("%s", nickname);
        trie.insert(nickname, 0, false);
    }
}
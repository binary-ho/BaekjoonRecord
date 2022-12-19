#include<iostream>
#include<string>
#include<vector>
#include<cstring>

#define C_SIZE 26
#define HASH_SIZE (1 << 22)
#define MAXN 5000
#define DIV (HASH_SIZE-1)

using namespace std;

int toNum(char c) { return c - 'a'; }
int teamMaxLength;

struct HashNode
{
    string key;
    HashNode* next;

    HashNode* alloc(string _key, HashNode* _next) {
        key = _key;
        next = _next;
        return this;
    }

    HashNode *getPrevNode(string _key) {
        HashNode* ptr = this;
        while (ptr->next) {
            if(ptr->next->key == _key) break;
            ptr = ptr->next;
        }
        return ptr;
    }
} nodePool[MAXN];
int poolCnt;
HashNode teamHashTable[HASH_SIZE];

void init() {
    poolCnt = 0;
    for (int i = 0; i < HASH_SIZE; i++) teamHashTable[i].next = nullptr;
}

int getKey(string str) {
    long long key = 5381;
    for (int i = 0; i < str.size(); i++) {
        key = ((key << 5) + key) + str[i] - 'a' + 1;
    }
    return (int) (key & DIV);
}

int target;
void addTeam(string key) {
    if (teamMaxLength < key.size()) teamMaxLength = key.size();
    target = getKey(key);
    teamHashTable[target].next = nodePool[poolCnt++].alloc(key, teamHashTable[target].next);
}

HashNode* prevNdoe;
bool findTeam(string key) {
    if (key.size() > teamMaxLength) return false;
    target = getKey(key);
    prevNdoe = teamHashTable[target].getPrevNode(key);
    if(prevNdoe->next != nullptr) return true;
    else return false;
}

struct TrieNode
{
    int terminal = 0;
    TrieNode* children[C_SIZE];

    TrieNode() {
        terminal = 0;
        memset(children, 0, sizeof(children));
    }

    void insert(const char* key, int terminalValue) {
        if (*key == 0) terminal = terminalValue;
        else {
            int next = toNum(*key);
            if (children[next] == nullptr) children[next] = new TrieNode();
            children[next]->insert(key + 1, terminalValue);
        }
    }
} colorRoot;

bool findColor(TrieNode *node_now, const char* key) {
    if(*key == 0) return false;
    if (node_now->terminal == 1) {
        if(findTeam(key)) return true;
    }
    int next = toNum(*key);
    if (node_now->children[next] == nullptr) return false;
    return findColor(node_now->children[next], key + 1);
}

int main() {

    int C, N, Q;
    cin >> C >> N;
    char buffer[1001], buffer2[2001];
    teamMaxLength = 0;
    for(int i = 0; i < C; i++) {
        scanf("%s", buffer);
        colorRoot.insert(buffer, 1);
    }
    
    init();
    for(int i = 0; i < N; i++) {
        scanf("%s", buffer);
        addTeam(buffer);
    }

    cin >> Q;
    for(int i = 0; i < Q; i++) {
        scanf("%s", buffer2);
        if(findColor(&colorRoot, buffer2)) printf("Yes\n");
        else printf("No\n");
    }
}
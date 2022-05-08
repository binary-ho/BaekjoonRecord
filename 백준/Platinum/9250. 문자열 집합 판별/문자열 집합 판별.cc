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
vector<int> str_vec;
//string str;
set<char> char_set;

vector<char> arr_copy (const char* arr) {
    vector<char> vec;
    int idx = 0;
    while(*arr) vec.emplace_back(*arr);
    return vec;
}

void string_copy (vector<int> &vec, string input) {
    vec.clear();
    for(int i = 0; i < input.size(); i++)vec.emplace_back((int)input[i]);
}
int keyCnt;
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

    TrieNode* find(const char* key) {
        if (*key == 0) return this;
        int next = toNum(*key);
        if (children[next] == nullptr) return nullptr;
        return children[next]->find(key + 1);
    }
    bool find(int idx) {
        if(terminal) return true;
        if(!str[idx]) return false;
        int next = toNum(str[idx]); // 개행문자 체크 필요
        if(children[next] == nullptr) return false; // 아예 가망도 없다
        return children[next]->find(idx + 1);
    }
    int find(int left, int right) {
        if(left == right) {
            if(terminal) return 1; // 완성된 문자열이 존재
            else return 0;  // 존재 X
        }
        int next = toNum(str_arr[left]);
        if(children[next] == nullptr) return -1; // 아예 가망도 없다
        return children[next]->find(left + 1, right);
    }
    int find(const char* key, int left, int right) {
        if(left == right) {
            if(terminal) return 1; // 완성된 문자열이 존재
            else return 0;  // 존재 X
        }
        int next = toNum(key[left]);
        if(children[next] == nullptr) return -1; // 아예 가망도 없다
        return children[next]->find(key, left + 1, right);
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
            if(next_node == nullptr) continue;    // 다음 철자 없으면 pass
            if(node_now == root) next_node->fail = root;
            else {
                // 부모의 실패 연결을 추적하며 실패 연결을 뒤져가며,
                // 접미사 노드중 현재 노드의 문자열에 다음 철자를 붙인 문자열의 접미사를 가지고 있는 노드를 찾습니다.
                TrieNode *ptr = node_now->fail;
                while(ptr != root && ptr->children[ch] == nullptr) ptr = ptr->fail;

                // 탐색하는 동안 발견 했을 경우 그 노드의 포인터를 가져옵니다.
                if(ptr->children[ch]) ptr = ptr->children[ch];
                next_node->fail = ptr;
                // 발견 못 했을 경우엔 자연스럽게 root node를 가르키게 되겠습니다.
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
            if(state->terminal) return true;
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
    keyCnt = 0;
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
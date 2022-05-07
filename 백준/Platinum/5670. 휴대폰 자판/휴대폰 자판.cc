#include<iostream>
#include<cstring>

#define C_SIZE 26
using namespace std;

int toNum(char c) { return c - 'a'; }

struct TrieNode
{
    bool check;
    int childten_cnt;
    TrieNode* children[C_SIZE];

    TrieNode() {
        check = false;
        childten_cnt = 0;
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (int i = 0; i < C_SIZE; i++) if(children[i]) delete children[i];
    }

    void insert(const char* key) {
        if (*key == 0) check = true;
        else {
            int next = toNum(*key);
            if (children[next] == nullptr) {
                childten_cnt++;
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
};

double sum;
void dfs(TrieNode &node, int type) {
    if(node.check) sum += type;
    bool auto_type = false;
    if(node.childten_cnt == 1 && !node.check && type != 0) {
        auto_type = true;
    }
    for(int i = 0; i < C_SIZE; i++) {
        if(node.children[i] == nullptr) continue;
        if(auto_type) dfs(*node.children[i], type);
        else dfs(*node.children[i], type + 1);
    }
}

int main() {
    char str[100001];
    int N = 1;
    //string str;
    while(N != EOF) {
        if(scanf("%d", &N) == EOF) break;
        TrieNode node;
        for(int i = 0; i < N; i++) {
            scanf("%s", str);
            //getline(str, cin);
            //printf("%s", str);
            node.insert(str);
        }
        sum = 0;
        dfs(node, 0);
        printf("%.2f\n", sum / N);
    }
}
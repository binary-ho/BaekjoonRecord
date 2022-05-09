#include<iostream>
#include<vector>
#include <queue>
#include <map>

using namespace std;
char buffer[21];


struct TrieNode
{
    int cnt = 0;
    bool terminal = false, save = false;
    map<char, TrieNode*> children;

    TrieNode() {
        cnt = 0;
        terminal = save = false;
        children = {};
    }
    void insert1(const char* key) {
        cnt++;
        if(*key != 0) {
            //int next = toNum(*key);
            char next = *key;
            if (children[next] == nullptr) {
                children[next] = new TrieNode();
            }
            children[next]->insert1(key + 1);
        } else {
            terminal = true;
        }
    }
    void insert2(const char* key) {
        save = true;
        if(*key != 0){
            char next = *key;
            if (children[next] == nullptr) {
                children[next] = new TrieNode();
            }
            children[next]->insert2(key + 1);
        }
    }
};

// 괜찮지 이제 아래는 안 봐도 된다는 마인드
int bfs(TrieNode &root) {
    int ans = 0;
    queue<TrieNode*> que;
    TrieNode* node_now;
    que.push(&root);
    while (!que.empty()) {
        node_now = que.front();
        que.pop();
        if(!node_now->save) {
            if(node_now->cnt > 1) ans += (node_now->cnt - 1);
            continue;
        }
        for(pair<char, TrieNode*> p : node_now->children) {
            /*if(!p.second->save && p.second->cnt > 1) {
                // 말로 해봐 뭘 구분해야 하는지
                // insert2의 끝은 save가 false 표시가 됨. 일치하는 경우가 없기는 한데
                // 하여간에 save인데 세어 지거나..
                //cout << p.first << " " << p.second->cnt << '\n';
                ans += p.second->cnt - 1;
                continue;
            }*/
            que.push(p.second);
        }
    }
    return ans;
}


int dfs_cnt;
void dfs(TrieNode node_now) {
    if(!node_now.save) {
        if(node_now.cnt > 1) dfs_cnt += (node_now.cnt - 1);
        return;
    }
    for(pair<char, TrieNode*> p : node_now.children) {
        dfs(*p.second);
    }
}


int main() {
    int T, N1, N2;
    cin >> T;
    while(T--) {
        TrieNode root;
        cin >> N1;
        for(int i = 0; i < N1; i++) {
            cin >> buffer;
            root.insert1(buffer);
        }
        cin >> N2;
        for(int i = 0; i < N2; i++) {
            cin >> buffer;
            root.insert2(buffer);
        }
        int ans = N1 - bfs(root);
        //dfs_cnt = 0;
        //dfs(root);
        //int ans = N1 - dfs_cnt;
        cout << ans << '\n';
    }
}
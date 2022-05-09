#include<iostream>
#include<vector>
#include <queue>
#include <map>


// #define C_SIZE 63
using namespace std;

char buffer[21];


struct TrieNode
{
    int cnt = 0;
    bool terminal = false, save = false;
    //TrieNode* children[C_SIZE];
    map<char, TrieNode*> children;

    TrieNode() {
        cnt = 0;
        terminal = save = false;
        //memset(children, 0, sizeof(children));
        children = {};
    }
    /*~TrieNode() {
        //for (int i = 0; i < C_SIZE; i++) if(children[i]) delete children[i];
        delete children;
    }*/

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
            //int next = toNum(*key);
            char next = *key;
            if (children[next] == nullptr) {
                children[next] = new TrieNode();
            }
            // 자기 자신 true
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
    //check[0] = true;
    // 어차피 중복 접근 시도 자체가 없기 때문에 check가 필요 없어.
    while (!que.empty()) {
        node_now = que.front();
        que.pop();
        if(!node_now->save) {
            //cout << "ans : " << ans;
            if(node_now->cnt > 1) ans += (node_now->cnt - 1);
            //cout << " -> " << ans << '\n';
            continue;
        }
        for(pair<char, TrieNode*> p : node_now->children) {
            /*if(!p.second->save && !p.second->terminal) {
                ans++;
                // 사실상 와일드 카드를 쓴 횟수인데
                // 와일드 카드를 썼는데도 단 하나 밖에 지우지 못 했다면?
                // 와일드 카드로 지워진 파일 갯수 - 1이 진정한 줄여진 갯수지
                continue;
            }*/
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

        /*for(int ch = 0; ch < C_SIZE; ch++) {
            if(!node_now->children[ch]) continue;
            // 컨셉이 뭐냐 save true일 경우 계속 진행하는데 save false인 경우 명령어 type가 가능!
            que.push(node_now->children[ch]);
        }*/
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
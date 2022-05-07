#include<iostream>
#include<cstring>

#define C_SIZE 26
#define MAXN 5000001
using namespace std;

int toNum(char c) { return c - 'a'; }

int trieCnt, keyCnt;
struct TrieNode
{
	int keyNum;
	TrieNode* children[C_SIZE];

	TrieNode() {
		keyNum = -1;
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
		for (int i = 0; i < C_SIZE; i++) {
			if (children[i]) delete children[i];
		}
	}

	void insert(const char* key) {
		//printf("%c", *key);
		if (*key == 0) keyNum = keyCnt++;
		else {
			int next = toNum(*key);
			if (children[next] == nullptr) {
				children[next] = new TrieNode();
			}
			children[next]->insert(key + 1);
		}
	}

	TrieNode* find(const char* key) {
		//printf("%c", *key);
		if (*key == 0) return this;
		int next = toNum(*key);
		if (children[next] == nullptr) return nullptr;
		return children[next]->find(key + 1);
	}
};


int main(int argc, char** argv)
{
	int N, M;
	cin >> N >> M;
	keyCnt = 0;
	char ch[500];
	TrieNode trieNode;
	for (int i = 0; i < N; i++) {
		scanf("%s", ch);
		trieNode.insert(ch);
		//printf("\n");
	}
	int ans = 0;
	TrieNode *nodeNow;
	for (int i = 0; i < M; i++) {
		scanf("%s", ch);
		nodeNow = trieNode.find(ch);
		if (nodeNow && nodeNow->keyNum != -1) ans++;
	}
	printf("%d", ans);
}
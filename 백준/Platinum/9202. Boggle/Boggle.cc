#include<iostream>
#include<cstring>
#include<vector>
#include <algorithm>
#include <stack>

#define C_SIZE 26
using namespace std;

int toNum(char c) { return c - 'A'; }

int trieCnt, keyCnt;
struct TrieNode
{
	// -1 없음, 0 있음, 1 꼬리
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
		if (*key == 0) {
			keyNum = keyCnt++;
			//return keyNum;
		}
		else {
			int next = toNum(*key);
			if (children[next] == nullptr) {
				children[next] = new TrieNode();
			}
			children[next]->insert(key + 1);
		}
	}
};


vector<string> vec;
vector<int> vecNum;
char map[4][4];

int dy[] = {0, 0, -1, -1, -1, 1, 1, 1};
int dx[] = {-1, 1, -1, 0, 1, -1, 0, 1};

bool cmp(const string& s1, const string& s2) {
	if (s1.size() != s2.size()) return s1.size() > s2.size();
	else return s1 < s2;
}
bool check[4][4];
// 반환 값은 찾아낸 문자열의 길이
int ansDfs;
//string S;
void dfs(int y, int x, int idx, string &S) {
	if (!S[idx + 1]) ansDfs = idx + 1;
	int newY, newX;
	for (int i = 0; i < 8; i++) {
		newY = y + dy[i];
		newX = x + dx[i];
		if (newY < 0 || newY >= 4 || newX < 0 || newX >= 4) continue;
		if (S[idx + 1] != map[newY][newX]) continue;
		if (check[newY][newX]) continue;
		//printf("통과 %d, %d 는 %c로 %d번째 철자 %c\n", newY, newX, map[newY][newX], idxNow + 1, str[idxNow + 1]);
		check[newY][newX] = true;
		dfs(newY, newX, idx + 1, S);
		check[newY][newX] = false;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	keyCnt = 0;
	//1글자, 2글자로 이루어진 단어는 0점, 3글자, 4글자는 1점, 5글자는 2점, 6글자는 3점, 7글자는 5점, 8글자는 11점이다. 
	//	점수는 자신이 찾은 단어에 해당하는 점수의 총 합이다.
	int w, b, num, ans, cnt, sizeArr[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
	bool isFind;
	char ch[9];
	string str;
	TrieNode trie, *wordNow;
	scanf("%d", &w);
	for (int i = 0; i < w; i++) {
		scanf("%s", &ch);
		trie.insert(ch);
		vec.emplace_back(ch);
	}
	
	sort(vec.begin(), vec.end(), cmp);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%s", map[j]);
		}
		ans = 0, cnt = 0;

		for (int j = 0; j < w; j++) {
			isFind = false;
			//wordNow = trie.find(vec[j]);
			//printf("%s 탐색 시작 \n", (vec[j]));

			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					if(vec[j][0] != map[y][x]) continue;
					//printf("%d, %d 에서 탐색 시작\n", y, x);
					
					//int ansBfs = bfs(y, x, vec[j]);
					// dfs 로 해보자
					ansDfs = 0;
                    memset(check, false, sizeof(check));
					check[y][x] = true;
					dfs(y, x, 0, vec[j]);
					check[y][x] = false;
					if (ansDfs != 0) {
						ans += sizeArr[ansDfs];
						isFind = true;
						if (cnt == 0) str = vec[j];
						cnt++;
						break;
					}
				}
				if(isFind) break;
			}
		}
		//cout << ans << " " << str << " " << cnt << '\n';
		printf("%d %s %d\n", ans, str.c_str(), cnt);
	}
}
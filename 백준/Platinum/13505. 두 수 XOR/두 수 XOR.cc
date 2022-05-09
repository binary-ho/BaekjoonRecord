#include<iostream>
#include<algorithm>
#include<vector>
#include <map>

using namespace std;

int limit;
long long ans;

string makeBinary(long long num) {
    string str = "";
    while(num != 0) {
        str += to_string(num & 1);
        num >>= 1;
    }
    if(limit != -1) while(str.size() < limit) str += "0";
    reverse(str.begin(), str.end());
    return str;
}

struct TrieNode
{
    TrieNode *children[2];

    TrieNode() {
        children[0] = children[1] = {};
    }
    void insertString(const string &str, int idx) {
        if(str[idx]) {
            int next = str[idx] - '0';
            if (children[next] == nullptr) {
                children[next] = new TrieNode();
            }
            children[next]->insertString(str, idx + 1);
        }
    }

    void find(const string &str, int idx, long long num) {
        if(!str[idx]) {
            ans = ans < num ? num : ans;
            return;
        }
        num <<= 1;
        if(children[1 - (str[idx] - '0')]) {
            num += 1;
            children[1 - (str[idx] - '0')]->find(str, idx + 1, num);
        }
        else children[(str[idx] - '0')]->find(str, idx + 1, num);
    }
};



int main() {
    int N;
    cin >> N;
    vector<long long> vec(N, 0);
    vector<string> str_vec;
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<long long>());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    limit = -1;
    string str;
    str = makeBinary(vec[0]);
    str_vec.emplace_back(str);
    limit = str.size();
    TrieNode root;
    root.insertString(str, 0);
    for(int i = 1; i < N; i++) {
        str = makeBinary(vec[i]);
        str_vec.emplace_back(str);
        root.insertString(str, 0);
    }
    ans =0;
    for(string str_now : str_vec) {
        root.find(str_now, 0, 0);
    }
    cout << ans;
    return 0;
}
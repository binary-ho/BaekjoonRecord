#include<iostream>
#include<vector>

using namespace std;

int N, u, v;
vector<int> friends[1000001];
bool rootCheck[1000001], check[1000001];
int earlyAdaptor[1000002][2], root;

void dfs(int nodeNow) {
    check[nodeNow] = true;
    for (int i = 0; i < friends[nodeNow].size(); i++) {
        int nextNdoe = friends[nodeNow][i];
        if (check[nextNdoe]) continue;
        dfs(nextNdoe);
        earlyAdaptor[nodeNow][0] += earlyAdaptor[nextNdoe][1];
        earlyAdaptor[nodeNow][1] += min(earlyAdaptor[nextNdoe][0], earlyAdaptor[nextNdoe][1]);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >>  v;
        friends[u].emplace_back(v);
        friends[v].emplace_back(u);
        rootCheck[v] = true;
    }

    for (int node = 1; node <= N; node++) {
        earlyAdaptor[node][1] = 1;
        if (!rootCheck[node]) root = node;
    }

    dfs(root);

    cout << min (earlyAdaptor[root][0], earlyAdaptor[root][1]);
}
#include <iostream>
#define DIV 1000000007
using namespace std;

int arr[1 << 17], leafNodeIdx[1 << 17];
pair<int, int> tree[1 << 18];

pair<int, int> makeTree(int nodeNow, int start, int end) {
    if (start == end) {
        leafNodeIdx[start] = nodeNow;
        return tree[nodeNow] = {arr[start], start};
    }
    int mid = (start + end)/2;
    pair<int, int> p1, p2;
    p1 = makeTree(nodeNow * 2, start, mid);
    p2 = makeTree(nodeNow * 2 + 1, mid + 1, end);
    return tree[nodeNow] = p1.first <= p2.first ? p1 : p2;
}

void updateTree(int idx, long long value) {
    arr[idx] = value;
    int leafIdx = leafNodeIdx[idx];
    tree[leafIdx] = {value, idx};
    leafIdx /= 2;
    while(leafIdx >= 1) {
        tree[leafIdx] = tree[leafIdx * 2].first <= tree[leafIdx * 2 + 1].first ? tree[leafIdx * 2] : tree[leafIdx * 2 + 1];
        leafIdx /= 2;
    }
}

pair<int, int> query(int nodeNow, int start, int end, int ans_left, int ans_right) {
    if (end < ans_left || ans_right < start) return {1000000001, -1};
    if (ans_left <= start && end <= ans_right) return tree[nodeNow];
    int mid = (start+end) / 2;
    pair<int, int> p1, p2;
    p1 = query(nodeNow * 2, start, mid, ans_left, ans_right);
    p2 = query(nodeNow * 2 + 1, mid + 1, end, ans_left, ans_right);
    return p1.first <= p2.first ? p1 : p2;
}

int main() {
    int N, M;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    makeTree(1, 1, N);
    scanf("%d", &M);
    int a, b, c;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            updateTree(b, c);
            continue;
        }
        printf("%d\n", query(1, 1, N, b, c).second);
    }
}
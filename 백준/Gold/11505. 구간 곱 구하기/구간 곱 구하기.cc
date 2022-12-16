#include <iostream>
#define DIV 1000000007
using namespace std;

int arr[1 << 20], leafNodeIdx[1 << 20];
long long tree[1 << 21];

long long makeTree(int nodeNow, int start, int end) {
    if (start == end) {
        leafNodeIdx[start] = nodeNow;
        return tree[nodeNow] = arr[start];
    }
    int mid = (start + end)/2;
    return tree[nodeNow] = makeTree(nodeNow * 2, start, mid) * makeTree(nodeNow * 2 + 1, mid + 1, end) % DIV;
}

void updateTree(int idx, long long value) {
    arr[idx] = value;
    int leafIdx = leafNodeIdx[idx];
    tree[leafIdx] = value;
    leafIdx /= 2;
    while(leafIdx >= 1) {
        tree[leafIdx] = tree[leafIdx * 2] * tree[leafIdx * 2 + 1] % DIV;
        leafIdx /= 2;
    }
}

long long getResult(int nodeNow, int start, int end, int ans_left, int ans_right) {
    if (end < ans_left || ans_right < start) return 1;
    if (ans_left <= start && end <= ans_right) return tree[nodeNow];
    int mid = (start+end) / 2;
    return getResult(nodeNow*2, start, mid, ans_left, ans_right) * getResult(nodeNow*2+1, mid+1, end, ans_left, ans_right) % DIV;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    makeTree(1, 1, N);
    int a, b;
    long long c;
    for (int i = 0; i < M + K; i++) {
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1) {
            updateTree(b, c);
            continue;
        }
        printf("%d\n", getResult(1, 1, N, b, c));
    }
}
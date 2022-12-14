#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, arr[1 << 17];
int maxTree[1 << 18], minTree[1 << 18];

void makeMinMaxTree(int node_now, int start, int end) {
    if(start == end) {
        maxTree[node_now] = minTree[node_now] = arr[start];
        return;
    }
    int mid = ((start + end) >> 1);
    makeMinMaxTree(node_now * 2, start, mid);
    makeMinMaxTree(node_now * 2 + 1, mid + 1, end);
    maxTree[node_now] = maxTree[node_now * 2] < maxTree[node_now * 2 + 1] ? maxTree[node_now * 2 + 1] : maxTree[node_now * 2];
    minTree[node_now] = minTree[node_now * 2] < minTree[node_now * 2 + 1] ? minTree[node_now * 2] : minTree[node_now * 2 + 1];
    return;
}

pair<int, int> getMinMax(int node_now, int start, int end, int ans_start, int ans_end) {
    if(ans_end < start || end < ans_start) return {1000000000, 1};
    if(ans_start <= start && end <= ans_end) return {minTree[node_now], maxTree[node_now]};
    int mid = (start+end)>>1;

    pair<int, int> p1 = getMinMax(node_now * 2, start, mid, ans_start, ans_end);
    pair<int, int> p2 = getMinMax(node_now * 2 + 1, mid + 1, end, ans_start, ans_end);
    int ans_min = p1.first < p2.first ? p1.first : p2.first;
    int ans_max = p1.second < p2.second ? p2.second : p1.second;
    return {ans_min, ans_max};
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    makeMinMaxTree(1, 1, N);

    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        pair<int, int> p = getMinMax(1, 1, N, a, b);
        printf("%d %d\n", p.first, p.second);
    }
}

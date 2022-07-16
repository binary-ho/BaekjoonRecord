#include <iostream>
#include <vector>
#include <algorithm>
#define ARR_SIZE 100001
using namespace std;
int N, M;
// 최솟값이랑, 갯수를 갖고 있는건 어때
int arr[ARR_SIZE], cnt_tree[1 << 18], max_tree[1 << 18];
vector<int> tree[1 << 18];

void make_tree(int node_now, int start, int end) {
    if(start == end) {
        tree[node_now] = { arr[start] };
        return;
    }
    int mid = ((start+end)>>1);
    make_tree(2 * node_now, start, mid);
    make_tree(2 * node_now + 1, mid + 1, end);
    int i = 0, j = 0, idx = 0, left_size = tree[2 * node_now].size(), right_size = tree[2*node_now+1].size();
    tree[node_now] = vector<int>(left_size + right_size);
    while(i<left_size && j <right_size) {
        if(tree[2*node_now][i] < tree[2*node_now+1][j]) tree[node_now][idx++] = tree[2*node_now][i++];
        else tree[node_now][idx++] = tree[2*node_now + 1][j++];
    }
    while(i<left_size) tree[node_now][idx++] = tree[2*node_now][i++];
    while(j<right_size) tree[node_now][idx++] = tree[2*node_now + 1][j++];
    return;
}

int i, j, k, ans;
void getAnswer(int node_now, int start, int end) {
    if(j < start || end < i) return;
    if(i <= start && end <= j) {
        ans += tree[node_now].end() - upper_bound(tree[node_now].begin(), tree[node_now].end(), k);
        return;
    }
    int mid = ((start+end)>>1);
    int left_one = 0, right_one = 0;
    getAnswer(node_now*2, start, mid);
    getAnswer(node_now*2+1, mid+1, end);
    return;
}


int main() {
    scanf("%d", &N);
    for(i = 1; i <= N; i++) cin >> arr[i];
    make_tree(1,1,N);
    scanf("%d", &M);
    while(M--) {
        scanf("%d %d %d", &i, &j, &k);
        ans = 0;
        getAnswer(1, 1, N);
        printf("%d\n", ans);
    }
}
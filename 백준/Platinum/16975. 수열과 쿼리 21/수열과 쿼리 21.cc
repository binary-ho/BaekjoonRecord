#include <iostream>
#define ARR_SIZE 100001
using namespace std;
int N, M;
long long tree[1 << 18], arr[ARR_SIZE], bias[1<<18];
int remember_idx[ARR_SIZE];

long long make_tree(int node_now, int start, int end) {
    if(start == end) {
        remember_idx[start] = node_now;
        return tree[node_now] = arr[start];
    }
    int mid = ((start + end) >> 1);
    return tree[node_now] = make_tree(node_now*2, start, mid) + make_tree(node_now*2+1, mid+1, end);
}

void add_bias(int node_now, int start, int end, int i, int j, int k) {
    if(end < i || j < start) return;
    if(i <= start && end <= j) { bias[node_now]+=k; return; }
    int mid = ((start+end)>>1);
    add_bias(node_now*2, start, mid, i, j, k);
    add_bias(node_now*2+1, mid+1, end, i, j, k);
    return;
}

long long getAnswer(int target_node) {
    int idx = remember_idx[target_node];
    long long ans = tree[idx] + bias[idx];
    while(idx > 1) {
        idx /= 2;
        ans += bias[idx];
    }
    return ans;
}


int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) cin >> arr[i];
    make_tree(1,1,N);
    scanf("%d", &M);
    int i, j, k, x, command;
    while(M--) {
        scanf("%d", &command);
        if(command == 1) {
            scanf("%d %d %d", &i, &j, &k);
            add_bias(1,1,N,i,j,k);
            continue;
        }
        scanf("%d", &x);
        printf("%lld\n", getAnswer(x));
    }
}
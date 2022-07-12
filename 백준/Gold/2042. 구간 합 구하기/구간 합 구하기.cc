#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N, M, K, arr[1000001], tree[1<<21];
int remember_idx[1000001];

long long make_tree(int node_now, int start, int end) {
    if(start == end) {
        remember_idx[start] = node_now;
        return tree[node_now] = arr[start];
    }
    int mid = ((start + end) >> 1);
    return tree[node_now] = make_tree(node_now*2, start, mid) + make_tree(node_now*2+1, mid+1, end);
}

void update_tree(int node_now, int start, int end, int target_node, int new_num) {
    if(start==end) {
        tree[target_node] = new_num;
        return;
    }
    int mid =((start+end)>>1);
    if(target_node <= mid) update_tree(2*node_now, start, mid, target_node, new_num);
    else update_tree(2*node_now+1, mid+1,end,target_node, new_num);
    tree[node_now] = tree[2*node_now] + tree[2*node_now+1];
    return;
}


long long get_sum(int node_now, int start, int end, int ans_start, int ans_end) {
    if(ans_end < start || end < ans_start) return 0;
    if(ans_start <= start && end <= ans_end) {
        return tree[node_now];
    }
    int mid = ((start+end)>>1);
    return get_sum(node_now*2, start, mid, ans_start, ans_end) + get_sum(node_now*2+1, mid+1, end, ans_start, ans_end);
}

int main() {
    scanf("%lld %lld %lld", &N, &M, &K);
    for(int i = 1; i <= N; i++){
        scanf("%lld", &arr[i]);
    }
    // 여기서 제작
    make_tree(1,1,N);


    long long a, b, c;
    for(int i = 0; i < M + K; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a==1) {
            //update_tree(1, 1, N, b, c);
            long long X = c - arr[b];
            arr[b] = c;
            // arr[remember_idx[b]] = c;
            int idx = remember_idx[b];
            while(idx >= 1) {
                tree[idx] += X;
                idx >>= 1;
            }
            continue;
        }
        printf("%lld\n", get_sum(1, 1, N, b, c));
    }
}

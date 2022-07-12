#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N, M, K, arr[1000001], tree[1<<21];
long long remember_idx[1000001];

long long make_tree(long long node_now, long long start, long long end) {
    if(start == end) {
        remember_idx[start] = node_now;
        return tree[node_now] = arr[start];
    }
    long long mid = ((start + end) >> 1);
    return tree[node_now] = make_tree(node_now*2, start, mid) + make_tree(node_now*2+1, mid+1, end);
}


long long get_sum(long long node_now, long long start, long long end, long long ans_start, long long ans_end) {
    if(ans_end < start || end < ans_start) return 0;
    if(ans_start <= start && end <= ans_end) {
        return tree[node_now];
    }
    long long mid = ((start+end)>>1);
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
            long long idx = remember_idx[b];
            while(idx >= 1) {
                tree[idx] += X;
                idx >>= 1;
            }
            continue;
        }
        printf("%lld\n", get_sum(1, 1, N, b, c));
    }
}

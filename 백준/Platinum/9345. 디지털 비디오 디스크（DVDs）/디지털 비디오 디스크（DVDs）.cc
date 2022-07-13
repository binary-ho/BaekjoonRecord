#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, K, Q, A, B;
// min, max
int tree_min[1<<18];
int tree_max[1<<18];
int remember_idx[100001];

void make_tree(int node_now, int start, int end) {
    if(start == end) {
        tree_min[node_now] = tree_max[node_now] = start;
        // start 번의 DVD는 실제 트리의 node_now 번째 idx에 있다!!
        remember_idx[start] = node_now;
        return;
        // return tree[node_now] = arr[start];
    }
    int mid = ((start + end) >> 1);
    make_tree(node_now*2, start, mid);
    make_tree(node_now*2+1, mid+1, end);
    tree_min[node_now] = tree_min[node_now*2] < tree_min[node_now*2+1] ? tree_min[node_now*2] : tree_min[node_now*2+1];
    tree_max[node_now] = tree_max[node_now*2] > tree_max[node_now*2+1] ? tree_max[node_now*2] : tree_max[node_now*2+1];
    return;
}

void update_tree(int target_node) {
    int idx = remember_idx[target_node];
    tree_max[idx] = tree_min[idx] = target_node;
    while(idx > 1) {
        idx /= 2;
        tree_min[idx] = tree_min[idx*2] < tree_min[idx*2+1] ? tree_min[idx*2] : tree_min[idx*2+1];
        tree_max[idx] = tree_max[idx*2] > tree_max[idx*2+1] ? tree_max[idx*2] : tree_max[idx*2+1];
    }
}


// 최소값은 내려갈 수록 커지지 더 작아지지는 않는다
int is_series_min(int node_now, int start, int end) {
    if(tree_min[node_now] > A || end < A || B < start) return 100001;
    if(A <= start && end <= B) return tree_min[node_now];
    int mid = ((start +end)>>1);
    int left_one, right_one;
    left_one = right_one = 100001;
    if(tree_min[node_now*2] <= A && mid >= A && start <= B) left_one = is_series_min(node_now*2, start, mid);
    if(tree_min[node_now*2+1] <= A && end >= A && mid+1 <= B) right_one = is_series_min(node_now*2+1, mid+1, end);
    return left_one < right_one ? left_one : right_one;
}

// 최대값도 작아지기만 하지 더 커지지는 않아
int is_series_max(int node_now, int start, int end) {
    if(tree_max[node_now] < B && end < A || B < start) return 0;
    if(A <= start && end <= B) return tree_max[node_now];
    int mid = ((start +end)>>1);
    int left_one, right_one;
    left_one = right_one = 0;
    if(tree_max[node_now*2] >= B && mid >= A && start <= B) left_one = is_series_max(node_now*2, start, mid);
    if(tree_max[node_now*2+1] >= B && end >= A && mid+1 <= B) right_one = is_series_max(node_now*2+1, mid+1, end);
    return left_one > right_one ? left_one : right_one;
}


int main() {

    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &K);
        make_tree(1, 1, N);
        while(K--) {
            scanf("%d %d %d", &Q, &A, &B);
            A++; B++;
            if(Q==0) {
                swap(remember_idx[A], remember_idx[B]);
                update_tree(A);
                update_tree(B);
                continue;
            }
            //printf("min: %d, max: %d\n", is_series_min(1,1,N,A,B), is_series_max(1,1,N,A,B));
            if(is_series_min(1,1,N)!=A || is_series_max(1,1,N)!=B) printf("NO\n");
            else printf("YES\n");
        }
    }
}

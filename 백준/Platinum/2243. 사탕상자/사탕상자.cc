#include <iostream>
#include <vector>
#include <algorithm>
#define BIAS 2097151
using namespace std;
int N, command, num, idx, temp, max_num, tree[4194504];
int query(int node_now, int start, int end, int X) {
    if(start == end) {
        return start;
    }
    else {
        int mid= ((start + end) >> 1);
        if (tree[node_now * 2] >= X) {
            return query((node_now << 1), start, mid, X);
        } else {
            return query((node_now << 1) + 1, mid+ 1, end, X - tree[node_now * 2]);
        }
    }
}

int main() {
    cin >> N;
    while (N--) {
        scanf("%d %d",&command,&num);
        if(command == 2) {
            scanf("%d", &temp);
            num += BIAS;
            while(num >= 1) {
                tree[num]+=temp;
                num>>=1;
            }
            continue;
        }
        max_num = query(1, 1, BIAS+1, num);
        printf("%d\n", max_num);
        max_num += BIAS;
        while(max_num >= 1) {
            tree[max_num]--;
            max_num>>=1;
        }
    }

}
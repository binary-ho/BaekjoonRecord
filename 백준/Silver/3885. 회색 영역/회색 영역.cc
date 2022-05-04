#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, W;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> N >> W;
        if(N == 0 && W == 0) return 0;
        int max_num = 0;
        vector<int> vec(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> vec[i];
            if(max_num < vec[i]) max_num = vec[i];
        }
        //sort(vec.begin(), vec.end(), greater<int>());
        int range = max_num / W;
        if(max_num % W != 0) range++;
        vector<int> limit;
        vector<double> cntRange(range, 0);
        for(int i = 1; i <= range; i++) {
            limit.emplace_back(i*W - 1);
        }
        double highest = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < range; j++) {
                if(vec[i] <= limit[j]) {
                    cntRange[j]++;
                    if(highest < cntRange[j]) highest = cntRange[j];
                    break;
                }
            }
        }
        double ans = 0;
        for(int i = 0; i < range; i++) {
            cntRange[i] /= highest;
            ans += (cntRange[i] * ((double)(range - i)/range));
            //cout << (cntRange[i] * ((double)(range - i)/range)) << " ";
        }
        ans += 0.01;

        cout << ans << '\n';
    }
}
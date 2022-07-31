#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
int N;
int main() {
    cin >> N;
    string str1, str2;
    cin >> str1;
    map<char, int> map1, map2;
    for(char ch: str1) {
        map1[ch]++;
    }
    // 더하거나, 뻬거나, 바꾸거나, 아예 같거나
    int ans = 0, cnt = 0;
    bool pass = false;
    for(int i = 1; i < N; i++){
        cin >> str2;
        map2 = {};
        for(char ch: str2) map2[ch]++;
        cnt = 0;
        if(str1.size() == str2.size()) {
            pass = false;
            for(auto p : map1) {
                if(map2[p.first] == p.second) continue;
                else if(map2[p.first] != p.second) {
                    if(abs(map2[p.first] - p.second) == 1) {
                        if(cnt == 1) {
                            cnt = 99999;
                            break;
                        }
                        if(!pass) {
                            pass = true;
                        } else {
                            pass = false;
                            cnt++;
                        }
                    } else {
                        cnt += 9999;
                        break;
                    }
                }
            }
            if(!pass && (cnt == 0 || cnt == 1)) { ans++;}
            else if (pass && cnt == 0) ans++;
        } else if (str1.size() + 1 == str2.size()) {
            for(auto p : map2) {
                if(map1[p.first] == p.second) continue;
                else if(map1[p.first] == p.second - 1) cnt++;
                else { cnt+=2; break; }
            }
            if(cnt == 1) { ans++;}
        } else if (str1.size() - 1 == str2.size()){
            for(auto p : map1) {
                if(map2[p.first] == p.second) continue;
                else if(map2[p.first] == p.second - 1) cnt++;
                else { cnt+=2; break; }
            }
            if(cnt == 1) { ans++;}
        } else {
            continue;
        }
    }
    cout << ans;
}
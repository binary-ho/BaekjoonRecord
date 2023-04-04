#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> mp;
    for (string str : participant) {
        mp[str]++;
    }
    
    for (string str : completion) {
        if (mp[str] != 0) {
            mp[str]--;
        }
    }
    
    for (pair<string, int> p : mp) {
        if (p.second == 0) continue;
        return p.first; 
    }
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    string ans = s;
    int length = (s.size() / 2) + 1;
    
    while (--length > 0) {
        int indexNow = 0;
        string ret = "";
        while (indexNow + length <= s.size()) {
            string strNow = s.substr(indexNow, length);
            indexNow += length;
            int count = 0;
            while (indexNow + length <= s.size() 
                   && strNow == s.substr(indexNow, length)) {
                indexNow += length;
                count++;
            }
            
            // 압축
            if (count != 0) {
                ret += to_string(count + 1);
            }
            ret += strNow;
        }
        
        if (indexNow < s.size()) {
            ret += s.substr(indexNow, s.size() - indexNow);
        }
        
        if (ans.size() > ret.size()) {
            ans = ret;
        }
    }
    
    return ans.size();
}
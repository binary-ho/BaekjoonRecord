#include <string>
#include <vector>

using namespace std;

string ansWord;
string dictionary = "AEIOU";
int ans = -1;
int index = 0;

void makeWord(int limit, string word) {
    if (ansWord == word) {
        ans = index;
        return;
    }
    
    if (limit == 0) {
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        index++;
        makeWord(limit - 1, word + dictionary[i]);
    }
}


int solution(string word) {
    ansWord = word;
    makeWord(5, "");
    return ans;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    
    int temp;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = i + 1; j < phone_book.size(); j++) {
            temp = 0;
            while (temp < phone_book[i].size() && temp < phone_book[j].size() 
                   && phone_book[i][temp] == phone_book[j][temp]) {
                temp++;
            }
            if (temp == phone_book[i].size() || temp == phone_book[j].size()) {
                return false;
            }
            break;
        }
    }
    return true;
}
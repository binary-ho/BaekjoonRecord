#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 2s+3의 세로
void print_num(int s, int num, int line_now) {
    switch (num) {
        case 1: {
            // 2일때 0 3 6 1일때 0 2 4
            for(int i = 0; i < s + 1; i++) {
                cout << " ";
            }
            if(line_now == 0 || line_now == s + 1 || line_now ==  2*s + 2) {
                cout << " ";
            } else {
                cout << "|";
            }
            return;
        }
        case 2: {
            if(line_now == 0 || line_now == s + 1 || line_now ==  2*s + 2) {
                for(int i = 0; i < s+2; i++) {
                    if(i == 0 || i == s + 1) {
                        cout << " ";
                    } else {
                        cout << "-";
                    }
                }
            } else if (line_now < s + 1) {
                for(int i = 0; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            } else {
                cout << "|";
                for(int i = 0; i < s + 1; i++) {
                    cout << " ";
                }
            }
            return;
        }
        case 3: {
            if(line_now == 0 || line_now == s + 1 || line_now ==  2*s + 2) {
                for(int i = 0; i < s+2; i++) {
                    if(i == 0 || i == s + 1) {
                        cout << " ";
                    } else {
                        cout << "-";
                    }
                }
            } else  {
                for(int i = 0; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            }
            return;
        }
        case 4: {
            if(line_now == 0 || line_now == 2*s + 2) for(int i = 0; i < s+2; i++) cout << " ";
            else if (line_now < s + 1) {
                cout << "|";
                for(int i = 1; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            } else if (line_now == s + 1) {
                for(int i = 0; i < s+2; i++) {
                    if(i == 0 || i == s + 1) {
                        cout << " ";
                    } else {
                        cout << "-";
                    }
                }
            }
            else {
                for(int i = 0; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            }
            return;
        }
        case 5: {
            if(line_now == 0 || line_now == s + 1 || line_now ==  2*s + 2) {
                for(int i = 0; i < s+2; i++) {
                    if(i == 0 || i == s + 1) {
                        cout << " ";
                    } else {
                        cout << "-";
                    }
                }
            } else if (line_now < s + 1) {
                cout << "|";
                for(int i = 0; i < s + 1; i++) {
                    cout << " ";
                }
            } else {
                for(int i = 0; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            }
            return;
        }
        case 6: {
            if(line_now == 0 || line_now == s + 1 || line_now ==  2*s + 2) {
                for(int i = 0; i < s+2; i++) {
                    if(i == 0 || i == s + 1) {
                        cout << " ";
                    } else {
                        cout << "-";
                    }
                }
            } else if (line_now < s + 1) {
                cout << "|";
                for(int i = 0; i < s + 1; i++) {
                    cout << " ";
                }
            } else {
                cout << "|";
                for(int i = 1; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            }
            return;
        }
        case 7: {
            if(line_now == 0) {
                for(int i = 0; i < s+2; i++) {
                    if(i == 0 || i == s + 1) {
                        cout << " ";
                    } else {
                        cout << "-";
                    }
                }
                return;
            }
            for(int i = 0; i < s + 1; i++) {
                cout << " ";
            }
            if(line_now == s + 1 || line_now ==  2*s + 2) {
                cout << " ";
            } else {
                cout << "|";
            }
            return;
        }
        case 8: {
            if(line_now == 0 || line_now == s + 1 || line_now ==  2*s + 2) {
                for(int i = 0; i < s+2; i++) {
                    if(i == 0 || i == s + 1) {
                        cout << " ";
                    } else {
                        cout << "-";
                    }
                }
            } else {
                cout << "|";
                for(int i = 1; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            }
            return;
        }
        case 9: {
            if(line_now == 0 || line_now == s + 1 || line_now ==  2*s + 2) {
                for(int i = 0; i < s+2; i++) {
                    if(i == 0 || i == s + 1) {
                        cout << " ";
                    } else {
                        cout << "-";
                    }
                }
            } else if (line_now > s + 1) {
                for(int i = 0; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            } else {
                cout << "|";
                for(int i = 1; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            }
            return;
        }
        case 0: {
            if(line_now == 0  || line_now ==  2*s + 2) {
                for(int i = 0; i < s+2; i++) {
                    if(i == 0 || i == s + 1) {
                        cout << " ";
                    } else {
                        cout << "-";
                    }
                }
            } else if (line_now == s + 1) {
                for(int i = 0; i < s+2; i++) {
                    cout << " ";
                }
            }
            else {
                cout << "|";
                for(int i = 1; i < s + 1; i++) {
                    cout << " ";
                }
                cout << "|";
            }
            return;
        }
        default: {
            return;
        }
    }
}

int main() {
   int s;
   string str;
   cin >> s >> str;
   for(int line_now = 0; line_now < 2 * s + 3; line_now++) {
       for(int i = 0; i < str.size(); i++) {
           print_num(s, str[i] - '0', line_now);
           cout << " ";
       }
       cout << '\n';
   }
}
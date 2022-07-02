#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;


int main() {
    string s1, s2;
    int n1 = 0, n2 = 0;
    cin >> s1 >> s2;
    // V, L, D 한번
    // I, X, C, M 연속 3번까지만 가능 근데 이건 최적이면 자동으로 처리됨
    // IV = 4, IV = 9 당연하네 아 1의 자리는 정해져 있어...
    // XL, = 40, XC = 90, 10의 자리도 정해져 있다.
    // CD = 400, CM = 900 아 ! 100의 자리도 정해져 있어. 그리디하게 가져가면 애초에 나올 수가 ㅇ벗음
    unordered_map<string, int> map;


    map.insert({"I", 1});
    map.insert({"II", 2});
    map.insert({"III", 3});
    map.insert({"IV", 4});
    map.insert({"V", 5});
    map.insert({"VI", 6});
    map.insert({"VII", 7});
    map.insert({"VIII", 8});

    map.insert({"X", 10});
    map.insert({"XX", 20});
    map.insert({"XXX", 30});
    map.insert({"XL", 40});
    map.insert({"L", 50});
    map.insert({"LX", 60});
    map.insert({"LXX", 70});
    map.insert({"LXXX", 80});

    map.insert({"C", 100});
    map.insert({"CC", 200});
    map.insert({"CCC", 300});
    map.insert({"CD", 400});
    map.insert({"D", 500});
    map.insert({"DC", 600});
    map.insert({"DCC", 700});
    map.insert({"DCCC", 800});

    string buffer = "";
    int idx= 0;
    while(s1[idx] == 'M') {
        buffer += s1[idx];
        idx++;
    }
    n1 += buffer.size()*1000;
    buffer = "";

    while(s1[idx] == 'D' || s1[idx] == 'C') {
        buffer += s1[idx];
        idx++;
    }
    if(s1[idx] == 'M') {
        n1 += 900;
        idx++;
    } else if(buffer.size() != 0){
        n1 += map[buffer];
    }
    buffer = "";

    while(s1[idx] == 'X' || s1[idx] == 'L') {
        buffer += s1[idx];
        idx++;
    }
    if(s1[idx] == 'C') {
        n1 += 90;
        idx++;
    } else if(buffer.size() != 0) {
        n1 += map[buffer];
    }
    buffer = "";

    while(s1[idx] == 'I' || s1[idx] == 'V') {
        buffer += s1[idx];
        idx++;
    }
    if(idx < s1.size() && s1[idx] == 'X') {
        n1 += 9;
    } else if(buffer.size() != 0) {
        n1 += map[buffer];
    }
    buffer = "";


    idx= 0;
    while(s2[idx] == 'M') {
        buffer += s2[idx];
        idx++;
    }
    n2 += 1000*buffer.size();
    buffer = "";

    while(s2[idx] == 'D' || s2[idx] == 'C') {
        buffer += s2[idx];
        idx++;
    }

    if(s2[idx] == 'M') {
        n2 += 900;
        idx++;
    } else if(buffer.size() != 0)  {
        n2 += map[buffer];
    }
    buffer = "";

    while(s2[idx] == 'X' || s2[idx] == 'L') {
        buffer += s2[idx];
        idx++;
    }
    if(s2[idx] == 'C') {
        n2 += 90;
        idx++;
    } else if(buffer.size() != 0) {
        n2 += map[buffer];
    }
    buffer = "";

    while(s2[idx] == 'I' || s2[idx] == 'V') {
        buffer += s2[idx];
        idx++;
    }

    if(s2[idx] == 'X') {
        n2 += 9;
    } else if(buffer.size() != 0)  {
        n2 += map[buffer];
    }
    buffer = "";
    // cout << n1 << " " << n2 << '\n';
    int ans1 = n1 + n2, temp, bias = 1;
    cout << ans1 << '\n';
    string str = to_string(ans1), roma[4], ans2;
    auto itr = map.begin();
    for(int i = 3; i >=  0; i--) {
        if(str.size() > i) {
            temp = str[i] - '0';

            if(bias == 1000) {
                for(int j = 0; j < temp; j++) ans2 += 'M';
                break;
            }
            temp *= bias;
            bias *= 10;
            if(temp != 0 && temp%9 == 0) {
                if(bias == 10) {
                    roma[i] = "IX";
                } else if(bias == 100) {
                    roma[i] = "XC";
                } else {
                    roma[i] = "CM";
                }
                continue;
            }
            for(;itr != map.end(); itr++) {
                if(itr->second == temp) {
                    roma[i] = itr->first;
                    break;
                }
            }

            itr = map.begin();
        }
    }
    for(int i = 0; i < 4; i++) ans2 += roma[i];
    cout << ans2 <<'\n';
}
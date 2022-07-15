#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#define ARR_SIZE 100001
using namespace std;
int N;

int day_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day_per_year[4] = {208, 366, 365};
double p[1001];

int date_to_num(string str) {
    int sec, min, hour, day, month, year, ans = 0, bias = 1;
    string buffer = "";
    string buffer2 = "";
    for(int i = str.size()-1; i >= 0; i--) {
        if(i == 16) {
            // sec
            buffer2 = buffer;
            buffer = "";
            reverse(buffer2.begin(), buffer2.end());
            bias *= 1;
            ans += stoi(buffer2)*bias;
        } else if (i == 13) {
            // min
            buffer2 = buffer;
            buffer = "";
            reverse(buffer2.begin(), buffer2.end());
            bias *= 60;
            ans += stoi(buffer2)*bias;
        } else if (i == 10) {
            // hour
            buffer2 = buffer;
            buffer = "";
            reverse(buffer2.begin(), buffer2.end());
            bias *= 60;
            ans += stoi(buffer2)*bias;
        } else if (i == 7) {
            // day
            buffer2 = buffer;
            buffer = "";
            reverse(buffer2.begin(), buffer2.end());
            bias *= 24;
            day = stoi(buffer2);
        } else if (i == 4) {
            // month
            buffer2 = buffer;
            buffer = "";
            reverse(buffer2.begin(), buffer2.end());
            month = stoi(buffer2);
        } else {
            // number
            buffer += str[i];
        }
    }
    // year
    buffer2 = buffer;
    buffer = "";
    reverse(buffer2.begin(), buffer2.end());
    year = stoi(buffer2);
    int m = 1;
    if(year == 2019) {
        m = 6;
        day -= 6;
    }
    for(;m < month; m++) {
        day += day_per_month[m];
        if(year == 2020 && m == 2) {
            day++;
        }
    }
    for(int y = 0; y < year - 2019; y++) {
        day += day_per_year[y];
    }
    ans += day*bias;
    return ans;
}

int main() {
    // int N;
    cin >> N;
    if(N==0) {
        cout << 0;
        return 0;
    }
    string buffer1, buffer2;
    vector<pair<string, int>> vec(N);
    for(int i = 0; i < N; i++) {
        cin >> buffer1 >> buffer2 >> vec[i].second;
        vec[i].first = buffer1 + " " + buffer2;
    }
    sort(vec.begin(), vec.end(), greater<>());
    int sec_365 = 60*60*24*365;
    int last_time = date_to_num(vec[0].first);
    double mother, son;
    for(int i = 0; i < N; i++) {
        p[i] = (double) max((double) pow(0.5, (double)(last_time - date_to_num(vec[i].first))/sec_365), (double) pow(0.9, i));
        //cout << p[i] << " " << vec[i].first << " " << date_to_num(vec[i].first) << " " << (double) pow(0.5, last_time - date_to_num(vec[i].first)/sec_365) << " " <<  (double) pow(0.9, i) << " " << "\n";
    }
    mother = son = 0;
    for(int i = 0; i < N; i++) {
        mother += (double)p[i]*vec[i].second;
        son += p[i];
    }
    cout << (int) (mother / son + 0.5) << '\n';

}
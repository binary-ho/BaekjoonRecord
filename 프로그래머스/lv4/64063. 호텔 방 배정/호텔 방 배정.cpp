#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> hotel;
long long reservation(long long room) {
    auto itr = hotel.find(room);
    if(itr == hotel.end()) {
        hotel.insert({room, room+1});
        return room;
    } else {
        long long ll = reservation(itr->second);
        itr->second = ll;
        return ll;
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {

    vector<long long> answer;
    for(long long room_now : room_number) {
        answer.emplace_back(reservation(room_now));
    }
    return answer;
}
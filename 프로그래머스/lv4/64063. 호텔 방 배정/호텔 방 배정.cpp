#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> hotel;
long long reservation(long long room) {
    auto itr = hotel.find(room);
    if(hotel[room] == 0) {
        hotel[room] =  room+1;
        return room;
    } else {
        hotel[room] = reservation(itr->second);
        return hotel[room];
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {

    vector<long long> answer;
    for(long long room_now : room_number) {
        answer.emplace_back(reservation(room_now));
    }
    return answer;
}
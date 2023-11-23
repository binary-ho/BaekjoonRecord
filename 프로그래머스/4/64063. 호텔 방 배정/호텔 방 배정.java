import java.util.*;

class Solution {
    
    Map<Long, Long> hotel = new HashMap<>();
    
    long reservation(long roomNumber) {
        // hotel
        if (!hotel.containsKey(roomNumber)) {
            hotel.put(roomNumber, roomNumber + 1);
            return roomNumber;
        } else {
            long room = reservation(hotel.get(roomNumber));
            hotel.put(roomNumber, room);
            return room;
        }
    }
    
    public long[] solution(long k, long[] roomNumbers) {
        long[] answer = new long[roomNumbers.length];
        for (int i = 0; i < roomNumbers.length; i++) {
            answer[i] = reservation(roomNumbers[i]);
        }
        return answer;
    }
}
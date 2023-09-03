import java.util.*;

class Solution {
    Integer mapSize = 0;
    Map<String, Integer> map = new HashMap();
    
    void insert(String key) {
        map.put(key, ++mapSize);
    }
    
    void initMap() {
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            insert(String.valueOf(ch));
        }
    }
    
    public int[] solution(String msg) {
        initMap();
        
        List<Integer> answer = new LinkedList<>();
        
        // 기본적으로 5초씩 걸려 근데 상관 없지 않나?
        int index = 0;
        while (index < msg.length()) {
            StringBuilder msgNow = new StringBuilder(msg.substring(index));
            
            Integer indexNumber = -1;
            while(msgNow.length() > 0) {
                indexNumber = map.getOrDefault(msgNow.toString(), -1);
                
                if (indexNumber != -1) {
                    break;
                }
                
                msgNow.delete(msgNow.length() - 1, msgNow.length());
            }
            
            answer.add(indexNumber);
            index += msgNow.length();

            if (index < msg.length()) {
                msgNow.append(msg.charAt(index));
                int result = map.getOrDefault(msgNow, -1);
                if (result == -1) {
                    insert(msgNow.toString());
                }
            };
        }
        
        return answer.stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}

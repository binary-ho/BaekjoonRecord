import java.util.*;

class Solution {
    
    private static boolean IN = true;
    private static boolean OUT = false;
    private static int LAST_TIME = 23 * 60 + 59;
    
    // 입 출 입 출
    Map<String, List<History>> historys = new HashMap<>();
        
    public int[] solution(int[] feeInfo, String[] records) {
        int basicTimeLimit = feeInfo[0];
        int basicFee = feeInfo[1];
        int unitTime = feeInfo[2];
        int feePerUnitTime = feeInfo[3];
        
        for (String record : records) {
            putHistoryByRecord(record);
        }
        
        // 각각을 계산
        List<Fee> fees = new LinkedList<>();
        for (Map.Entry<String, List<History>> entry : historys.entrySet()) {
            String carName = entry.getKey();
            List<History> list = entry.getValue();
            if (list.size() % 2 == 1) {
                list.add(new History(LAST_TIME, OUT));
            }
            
            // 필요 없을 수도 있어.
            list.sort((h1, h2) -> {
                if (h1.timestamp > h2.timestamp) {
                   return 1;
                } 
                return -1;
            });
            
            int index = 0;
            int totalTime = 0;
            while (index < list.size() - 1) {
                // 정상 케이스
                History in = list.get(index);
                History out = list.get(index + 1);
                totalTime += out.timestamp - in.timestamp;
                index += 2;
            }
            
            int amount = basicFee;
            int overTime = totalTime - basicTimeLimit;
            if (overTime > 0) {
                int unit = overTime / unitTime;
                if (overTime % unitTime != 0) {
                    unit++;
                }
                amount += unit  * feePerUnitTime;
            }
            fees.add(new Fee(Integer.valueOf(carName), amount));
        }
        
        fees.sort((f1, f2) -> {
            if (f1.carNumber > f2.carNumber) {
                return 1;
            }
            return -1;
        });
        
        int[] answer = new int[fees.size()];
        for (int i = 0; i < fees.size(); i++) {
            answer[i] = fees.get(i).fee;
        }
        return answer;
    }
    
    void putHistoryByRecord(String record) {
        String[] records = record.split(" ");
        int timestamp = getTimestamp(records[0]);
        boolean isIn = OUT;
        if (records[2].equals("IN")) {
            isIn = IN;
        }
        
        putHistory(records[1], new History(timestamp, isIn));
    }
    
    void putHistory(String carNumber, History history) {
        if (!historys.containsKey(carNumber)) {
            historys.put(carNumber, new ArrayList<>());
        }
        
        historys.get(carNumber).add(history);
    }
    
    int getTimestamp(String time) {
        String[] times = time.split(":");
        return Integer.valueOf(times[0]) * 60 + Integer.valueOf(times[1]);
    }
    
    class History {
        int timestamp;
        boolean isIn;
        
        History(int timestamp, boolean isIn) {
            this.timestamp = timestamp;
            this.isIn = isIn;
        }
    }
    
    class Fee {
        int carNumber;
        int fee;
        
        Fee(int carNumber, int fee) {
            this.carNumber = carNumber;
            this.fee = fee;
        }
    }
}
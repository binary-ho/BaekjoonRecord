import java.util.*;

class Solution {
    
    List<Duration> durations;
    // 1초동안 가장 갯수 많은 곳 찾기
    // 매번 시작 끝만 전부 조사해도 천천
    public int solution(String[] lines) {
        
        durations = new ArrayList<>(lines.length);
        for (String line : lines) {
            String[] times = line.split(" ");
            durations.add(new Duration(times[1], times[2]));
        }
        
        int answer = 0;
        for (Duration duration : durations) {
            int from = duration.from;
            int to = duration.to;
            
            int[] cnts = new int[4];
            
            // +-999
            for (int i = 0; i < durations.size(); i++) {
                
                Duration durationNow = durations.get(i);
                
                if (from - 999 <= durationNow.to && durationNow.from <= from) {
                    cnts[0]++;
                } else if (from <= durationNow.to &&  durationNow.from <= from + 999) {
                    cnts[1]++;
                } else if (to - 999 <= durationNow.to && durationNow.from <= to) {
                    cnts[2]++;
                } else if (to <= durationNow.to && durationNow.from <= to + 999) {
                    cnts[3]++;
                }
            }
            
            for (int cnt : cnts) {
                if (answer >= cnt) continue;
                answer = cnt;
            }
        }
        
        return answer;
    }
    
    // 전날 시작 있을 수도??
    class Duration {
        int from;
        int to;
        
        Duration(String timestamp, String millis) {
            String[] times = timestamp.split(":");
            
            this.to = Integer.valueOf(times[0]) * 60 * 60 + Integer.valueOf(times[1]) * 60;
            this.to += Integer.valueOf(times[2].substring(0, 2));
            this.to *= 1000;
            this.to += Integer.valueOf(times[2].substring(3, 6));
            
            this.from = this.to 
                    - (Integer.valueOf(millis.substring(0, 1)) * 1000)
                    + 1;
            
            if (millis.contains(".")) {
                this.from -= (Integer.valueOf(millis.substring(2, millis.length() - 1)));
            }
        }
    }
}
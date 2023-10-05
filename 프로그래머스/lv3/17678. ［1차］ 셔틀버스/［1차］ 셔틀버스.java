import java.util.*;
import java.util.stream.*;

class Solution {
    // 9:52
    // 해당 시간까지 딱 탈 수 있음
    // 9시 ~ (9시 + n * t) 사이에 n * m등 안에 드는 최소 시간 
    
    // 2000 * log 1440 -> 아주 작다
    private List<Integer> times;
    public String solution(int n, int t, int m, String[] timetable) {
        times = Arrays.stream(timetable)
            .map(time -> time.split(":"))
            .map(hourMin -> Integer.valueOf(hourMin[0]) * 60 + Integer.valueOf(hourMin[1]))
            .sorted()
            .collect(Collectors.toList());
        
        int left = 0;
        int right = 9 * 60 + (n - 1) * t;
        int latest = 0;
        
        // upper_bound
        while (left <= right) {
            int time = (left + right) / 2;
            int order = getOrder(time);
            
            if (canRide(n, t, m, order)) {
                // 탈 수 있다.
                if (latest < time) {
                    latest = time;
                }
                
                if (left == time) {
                    left = time + 1;
                } else {
                    left = time;
                }
                
            } else {
                right = time;
                if (left == right) break;
            }
        }
        
        String hour = String.valueOf(latest / 60);
        if (hour.length() == 1) {
            hour = "0" + hour;
        }
        
        String min = String.valueOf(latest % 60);
        if (min.length() == 1) {
            min = "0" + min;
        }
        String answer = hour + ":" + min;       
        return answer;
    }
    
    int getOrder(int time) {
        int left = 0;
        int right = times.size() - 1;
        
        if (time < times.get(left)) {
            return 1;
        }
        
        int order = times.size() + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (times.get(mid) <= time) {
                if (left != mid) {
                    left = mid;
                } else {
                    left = mid + 1;
                }
                
            } else {
                if (order > right + 1) {
                    order = right + 1;
                }
                
                if (right != mid) {
                    right = mid;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return order;
    }
    
    boolean canRide(int n, int t, int m, int order) {
        int timeNow = 9 * 60;
        int idx = 0;
        
        for (int i = 0; i < n && idx < times.size(); i++) {
            for (int j = 0; j < m; j++) {
                if (idx + 1 >= order) {
                    return true;
                }
                
                if (idx == times.size() || times.get(idx) > timeNow) break;
                
                idx++;
            }

            timeNow += t;
        }
        
        return false;
    }
}
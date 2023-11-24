import java.util.*;
import java.util.stream.*;

class Solution {
    
    // 12 : 45 ~ 1시 25분까지 해보자
    // 어떤 구간에 가장 많이 시청했나?
    // 30만이면 그냥 다 체크해도 돼
    
    // 그러지말고 최악 36만분이니까
    // 시작과 끝을 만들어서 투포인터 이동?
    int[] startCount;
    int[] endCount;
    
    public String solution(String playTime, String advertiseTime, String[] logs) {
        // 그래프 초기화
        int playTimeSecond = getSecond(playTime);
        startCount = new int[playTimeSecond + 1];
        endCount = new int[playTimeSecond + 1];
        
        String answer = "";
        // TODO : 되는거 안 되는거 미리 확인
        // System.out.println("test-test".split("-").length);

        Arrays.stream(logs)
            .forEach(this::checkStartEndTime);
        
        int advertiseTimeSecond = getSecond(advertiseTime);
        // 초기 세팅
        int right = 0;  // 찐 시청 시간
        long timeCount = 0;
        int rightUserCount = 0;  // right 시청 인원이나 마찬가지
        while (right < advertiseTimeSecond && right <= playTimeSecond) {
            rightUserCount += startCount[right];
            rightUserCount -= endCount[right++];
            
            timeCount += rightUserCount;
        }

        int left = 0;
        int leftUserCount = 0;  
        
        int answerTime = left;
        long maxTimeCount = timeCount;
        while (right <= playTimeSecond) {
            // left에서 원래 보던 사람 빼주고 이동
            leftUserCount += startCount[left];
            leftUserCount -= endCount[left++];
            
            timeCount -= leftUserCount;
            
            // right에서 새로운 사람 반영해주고 계산
            rightUserCount += startCount[right];
            rightUserCount -= endCount[right++];
            
            timeCount += rightUserCount;
            
            if (maxTimeCount < timeCount) {
                maxTimeCount = timeCount;
                answerTime = left;
            }
        }
        
        return getTime(answerTime);
    }
    
    void checkStartEndTime(String log) {
        String[] watchTimes = log.split("-");
        startCount[getSecond(watchTimes[0])]++;
        endCount[getSecond(watchTimes[1])]++;
    }
    
    int getSecond(String time) {
        String[] times = time.split(":");
        int second = Integer.valueOf(times[2]);
        int minuate = Integer.valueOf(times[1]) * 60;
        int hour = Integer.valueOf(times[0]) * 60 * 60;
        return second + minuate + hour;
    }
    
    String getTime(int seconds) {
        int second = seconds % 60;
        int minuate = seconds / 60 % 60;
        int hour = seconds / (60 * 60);
        
        StringBuilder stringBuilder = new StringBuilder();
        
        
        return stringBuilder.append(getTimeExpression(hour))
            .append(":")
            .append(getTimeExpression(minuate))
            .append(":")
            .append(getTimeExpression(second))
            .toString();
    }
    
    String getTimeExpression(int time) {
        String expression = String.valueOf(time);
        if (expression.length() < 2) {
            return "0" + expression;
        }
        return expression;
    }
}
import java.util.*;

class Solution {
    
    // 12 : 05
    // 12 // 28일
    
    private static final int MONTH = 12;
    private static final int DAYS = 28;
    private final Map<String, Integer> expires = new HashMap<>();
    public int[] solution(String todayOrigin, String[] termsOriginal, String[] privacies) {
        
        for (String term : termsOriginal) {
            String[] nameAndTerm = term.split(" ");
            int dayTerm = Integer.valueOf(nameAndTerm[1]) * DAYS;
            expires.put(nameAndTerm[0], dayTerm);
        }
        
        List<Integer> answers = new LinkedList<>();
        int today = getPrivacyDays(todayOrigin);
        for (int i = 0; i < privacies.length; i++) {
            String[] privacyAndExpired = privacies[i].split(" ");
            int privacy = getPrivacyDays(privacyAndExpired[0]);
            int expired = expires.get(privacyAndExpired[1]);
            
            int expiredDay = privacy + expired;
            if (expiredDay <= today) {
                answers.add(i + 1);
            }
        }
        
        // toArray는 래퍼런스 형에서만 가능하다고 하네...
        // return answers.toArray(new int[answers.size()]);
        return answers.stream()
            .mapToInt(i -> i)
            .toArray();
    }
    
    int getPrivacyDays(String privacy) {
        String[] times = privacy.split("\\.");
        int year = Integer.valueOf(times[0]) * DAYS * MONTH;
        int month = Integer.valueOf(times[1]) * DAYS;
        int day = Integer.valueOf(times[2]);
        
        return year + month + day;
    }
}
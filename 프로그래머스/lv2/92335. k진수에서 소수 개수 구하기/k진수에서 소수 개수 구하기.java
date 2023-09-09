import java.util.*;
class Solution {
    
    boolean isPrime(long num) {
        if (num == 1) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    List<Integer> zeros = new LinkedList<>();
    
    public int solution(int n, int k) {
        int answer = 0;
        // 11 1011
        // 5, 1
        // 10
        // 2, 11
        // 1, 011
        // 0, 1011
        
        StringBuilder stringBuilder = new StringBuilder();
        
        while (n > 0) {
            int left = n % k;
            n /= k;
            stringBuilder.append(left);
        }
        stringBuilder.reverse();
        // 1. 얘 자체가 소수
        // 2. 0을 찾아서 외곽 조사
        // 3. 아니면 말고
        
        String number = stringBuilder.toString();
        for (int i = 0; i < number.length(); i++) {
            if (number.charAt(i) != '0') continue;
            zeros.add(i);
        }
        
        // 1번 체크
        if (zeros.isEmpty()) {
            long longNumber = Long.parseLong(number);
            if (isPrime(longNumber)) {
                return 1;
            } else {
                return 0;
            }
        } 
        
        // 2번 3번 체크
        String twoString = number.substring(0, zeros.get(0));
        long two = Long.parseLong(twoString);
        if (isPrime(two) && notHasZero(twoString)) {
            answer++;
        }


        String threeString = number.substring(zeros.get(zeros.size() - 1) + 1);
        if (!threeString.isEmpty()) {
            long three = Long.parseLong(threeString);
            if (isPrime(three) && notHasZero(threeString)) {
                answer++;
            }
        }


        for (int i = 0; i < zeros.size() - 1; i++) {
            String substring = number.substring(zeros.get(i) + 1, zeros.get(i + 1));
            if (substring.isEmpty()) continue;

            long subnumber = Long.parseLong(substring);
            if (isPrime(subnumber) && notHasZero(substring)) {
                answer++;
            }
        }
        return answer;
    }
    
    boolean notHasZero(String number) {
        if (number.charAt(0) == '0') {
            number = number.substring(1);
        }
        
        if (number.charAt(number.length() - 1) == '0') {
            number = number.substring(0, number.length());
        }
        int index = number.indexOf('0');
        return index == -1 ? true : false;
    }
}
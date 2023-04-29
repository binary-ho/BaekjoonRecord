import java.util.*;

// 중위 순회?
// 1 -> 1만 됨
// 111 -> 2가 무조건 포함, 2, 3, 6, 7
// 111 1 111 -> 8이 무조건 포함 8, 8 + 2, 8 + 32, 8 + 2 + 4, 8 + 2 + 1도 되고
// 1, 2, 4, 

// 0101010
// 101 부모가 없어.
// 64 -> 7자리 숫자
// 포화 이진트리가 되어야 한다
// 1, 7, ... 2^n - 1 형태
// 1 3 7

// 검증은 이분 탐색이라 빨라 
// 이진수화는?
class Solution {
    static int LIM = 50;
    long[] zero = new long[LIM];
    long[] two = new long[LIM];
    int[] one = new int[10001];
    
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];
        init();
        
        String str;
        int oneCnt;
        long num;
        for (int i = 0; i < numbers.length; i++) {
            num = numbers[i];
            str = getBinaryHo(i, num);
            
            oneCnt = divide(str, 0, str.length() - 1);
            answer[i] = oneCnt == one[i] ? 1 : 0;
        }
        
        return answer;
    }
    
    // 하나 뺴고 2로 나눠
    private int divide(String binaryHo, int start, int end) {
        if (start == end) {
            return binaryHo.charAt(start) - '0';
        }
        
        int mid = (start + end) / 2;
        if (binaryHo.charAt(mid) == '1') {
            return divide(binaryHo, start, mid - 1) 
                + divide(binaryHo, mid + 1, end) + 1;
        }
        
        return 0;
    }
    
    private String getBinaryHo(int idx, long num) {
        long temp = num;
        long oneTwo;
        StringBuilder st = new StringBuilder();
        while (temp > 0) {
            oneTwo = temp % 2;
            if (oneTwo == 1) {
                one[idx]++;
            }
            st.append(oneTwo);
            temp /= 2;
        }
        long width = findWidth(st.length());
        while (st.length() < width) {
            st.append(0);
        }
        return st.reverse().toString();
    }
    
    // 1층에 1
    // 2층에 3
    // 1보다 크면 2층
    private long findWidth(int num) {
        for (int i = 1; i < LIM - 1; i++) {
            if (two[i] <= num && num < two[i + 1]) {
                return two[i + 1] - 1;                
            }
        }
        return 1;
    }
    
    private void init() {
        two[0] = 1;
        for (int i = 1; i < LIM; i++) {
            two[i] = two[i - 1] * 2;
        }
    }
}
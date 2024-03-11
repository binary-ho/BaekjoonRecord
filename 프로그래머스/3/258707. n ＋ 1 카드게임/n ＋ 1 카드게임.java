import java.util.*;

class Solution {
    
    // 그리디라는걸 대체 어떻게 추정한거야
    int n;
    public int solution(int coin, int[] cards) {
        n = cards.length;
        // 있으면 먹고
        // 없으면 이제까지 먹은 것 중에 있나 확인
        List<Integer> hands = new LinkedList<>();
        int made = 0;
        int madeTarget = n + 1;
        
        for (int s = 0; s < n / 3; s++) {
            int card = cards[s];
            
            int pair = madeTarget - card;
            if (hands.contains(pair)) {
                made++;
                continue;
            } 

            hands.add(card);
        }
        
        List<Integer> temps = new LinkedList<>();
        int stage = 1;
        for (int s = n / 3; s < n; s += 2, stage++) {
            int card1 = cards[s];
            int card2 = cards[s + 1];
            
            temps.add(card1);
            temps.add(card2);
            
            if (made > 0) {
                made--;
                continue;
            } 
            
            // temp랑 hands 비교
            if (coin < 1) {
                break;
            }
            
            boolean isFind = false;
            for (int temp : temps) {
                if (hands.contains(madeTarget - temp)) {
                    temps.remove(Integer.valueOf(temp));
                    coin--;
                    isFind = true;
                    break;
                }
            }
            
            if (isFind) continue;
            
            if (coin < 2) {
                break;
            } 
            
            for (int temp : temps) {
                if (temps.contains(madeTarget - temp)) {
                    temps.remove(Integer.valueOf(temp));
                    temps.remove(Integer.valueOf(madeTarget - temp));
                    coin -= 2;
                    isFind = true;
                    break;
                }
            }
            
            if (!isFind) {
                break;
            }
        }
        return stage;
    }
}
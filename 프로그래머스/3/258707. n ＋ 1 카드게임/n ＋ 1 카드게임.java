import java.util.*;

class Solution {
    
    // 그리디라는걸 대체 어떻게 추정한거야
    // DP로 안 될거 같으면 그리디로 가는게 맞는건가.....
    int n;
    public int solution(int coin, int[] stageCards) {
        n = stageCards.length;
        // 있으면 먹고
        // 없으면 이제까지 먹은 것 중에 있나 확인
        List<Integer> hands = new LinkedList<>();
        int made = 0;
        int madeTarget = n + 1;
        
        for (int s = 0; s < n / 3; s++) {
            int card = stageCards[s];
            
            int pair = madeTarget - card;
            if (hands.contains(pair)) {
                hands.remove(Integer.valueOf(pair));
                made++;
                continue;
            } 

            hands.add(card);
        }
        
        // 한 330 스테이지
        // 거기까지 갈 수 있는지? -> 스테이지 정하고, 직접 해보기 -> 300번도 연산 안 든다
        
        int answer = 0;
        int left = 1;
        int right = n / 3 + 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            System.out.println("mid : " + mid);
            if (isPossible(mid, new LinkedList(hands), made, madeTarget, coin, stageCards)) {
                left = mid + 1;
                answer = Math.max(answer, mid);
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
    
    boolean isPossible(int expectedStageLimit, List<Integer> hands, int made, int madeTarget, int coin, int[] stageCards) {
        if (made + 1 >= expectedStageLimit) {
            return true;
        }
        
        int s = n / 3;
        List<Integer> temp = new LinkedList<>();
        int madeNow = made;
        int stage = 1;
        int coinNow = coin;
        while (stage <= madeNow) {
        // for (; s < n / 3 + madeNow; s += 2, stage++) {
            int card1 = stageCards[s];
            int card2 = stageCards[s + 1];
            
            if (coinNow > 0 && hands.contains(madeTarget - card1)) {
                System.out.println("1");
                coinNow--;
                madeNow++;
                temp.add(card2);
            } else if (coinNow > 0 && hands.contains(madeTarget - card2)) {
                System.out.println("2");
                coinNow--;
                madeNow++;
                temp.add(card1);
            } else if (coinNow > 0 && temp.contains(madeTarget - card1)) {
                coinNow--;
                System.out.println("3");
                madeNow++;
                temp.add(card2);
            } else if (coinNow > 0 && temp.contains(madeTarget - card2)) {
                coinNow--;
                madeNow++;
                System.out.println("4");
                temp.add(card1);
            } else if (coinNow > 1 && card1 + card2 == madeTarget) {
                coinNow -= 2;
                madeNow++;
                System.out.println("5");
            } else {
                temp.add(card1);
                temp.add(card2);
            }
            s += 2; stage++;
        }
        
        System.out.println("stage : " + stage);
        System.out.println("madeNow : " + madeNow);
        return stage >= expectedStageLimit;
    }
    
    boolean removeIfContains(List<Integer> list, Integer target, Integer count) {
        if (list.contains(target)) {
            // list.remove(target);
            // count++;
            return true;
        }
        return false;
    }
}
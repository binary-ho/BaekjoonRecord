import java.util.*;

class Solution {
    // 퍼센트 아래는 구매조차 하지 않는다.
    // 일단 퍼센트 찍어야 구매하고, 구매금액 가격 넘으면 가입
    // 가입자수가 가장 많은 경우
    // 가장 많은 경우 중에선 매출 액이 가장 많은 경우
    // 몇 명이나 가입할 수 있는가?
    // 100명이고 이모티콘은 7개 밖에 안한다.
    // 가입은 시켜야지, 최소 가입 조건을 찾으시오
    // 각 사람별로 N% 이상이면 구매한다 N이 넘는 a% b% c% d% 일때 가입 확정 
    // 100짜리 20% 200짜리 30퍼 -> 300일때는 
    // 걍 가입을 시키는게 목표 최대한 많이 구매를 시켜야 한다.
    // 다 구매하도록?
    
    int n, m;
    Integer[] discount = {10, 20, 30, 40};
    int ansUserCnt = 0;
    int total = 0;
    
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = {0, 0};
        
        // discount = new ArrayList<>();
        n = users.length;
        m = emoticons.length;
        
        int percentMin = 40;
        for (int i = 0; i < n; i++) {
            if (percentMin > users[i][0]) {
                percentMin = users[i][0];
            }
        }
        
        emoticonDiscount(0, new ArrayList<Integer>(), users, emoticons);
        answer[0] = ansUserCnt;
        answer[1] = total;
        return answer;
    }
    
    private void checkUserPurchase(ArrayList<Integer> pol, int[][] users, int[] emoticons) {
        
        // 유저 하나하나에 적용합니다.
        // 유저가 제시한 비율 보다 높은 정책이라면 수용하고 구매 가격 혹은 가입 여부를 결정합니다.
        int userCnt = 0;
        int amount = 0, amountTemp;
        for (int i = 0; i < users.length; i++) {
            amountTemp = 0;
            for (int j = 0; j < pol.size(); j++) {
                if (pol.get(j) < users[i][0]) continue;
                amountTemp += ((100 - pol.get(j)) * emoticons[j]) / 100;
            }
            
            if (users[i][1] <= amountTemp) {
                userCnt++;
            } else {
                amount += amountTemp;
            }
        }
        // 갱신
        if (ansUserCnt <= userCnt) {
            if (ansUserCnt == userCnt) {
                total = amount < total ? total : amount;
            } else {
                total = amount;
            }
            ansUserCnt = userCnt;
        }
    }
    
    // 하나의 할인 정책을 정하고 유저에게 적용
    private void emoticonDiscount(int eIdx, ArrayList<Integer> pol, int[][] users, int[] emoticons) {
        if (eIdx == m) {
            checkUserPurchase(pol, users, emoticons);
            return;
        }
        
        for (int j = 0; j < discount.length; j++) {
            pol.add(discount[j]);
            emoticonDiscount(eIdx + 1, pol, users, emoticons);
            pol.remove(pol.size() - 1);
        }
    }
}
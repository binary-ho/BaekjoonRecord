class Solution {
    
    // 4 : 12
    // 맨하탄 거리로 단순하게 계산하자.
    
    int[] axies = { 10, 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    
    public String solution(int[] numbers, String hand) {
        StringBuilder stringBuilder = new StringBuilder();
        
        int left = 9;
        int right = 11;
        
        for (int number : numbers) {
            int axis = axies[number];
            if (axis % 3 == 0) {
                // 왼손
                stringBuilder.append("L");
                left = axis;
            } else if (axis % 3 == 2) {
                // 오른손
                stringBuilder.append("R");
                right = axis;
            } else {
                int leftMove = calculateDistance(left, axis);
                int rightMove = calculateDistance(right, axis);
                if (leftMove < rightMove) {
                    stringBuilder.append("L");
                    left = axis;
                } else if (leftMove > rightMove) {
                    stringBuilder.append("R");
                    right = axis;
                } else {
                    if (hand.equals("left")) {
                        stringBuilder.append("L");
                        left = axis;
                    } else {
                         stringBuilder.append("R");
                        right = axis;
                    }
                }
            }
        }
        
        
        return stringBuilder.toString();
    }
    
    int calculateDistance(int from, int to) {
        int fromY = from / 3;
        int fromX = from % 3;
        
        int toY = to / 3;
        int toX = to % 3;
        
        return Math.abs(fromY - toY) + Math.abs(fromX - toX);
    }
}
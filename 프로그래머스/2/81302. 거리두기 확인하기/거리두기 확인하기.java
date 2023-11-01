import java.util.*;

class Solution {
    
    // 9:45
    // 파티션 있거나 2 초과만 된다.
    // 파티션이 없거나 2 이하면 안 된다.
    // P, O
    private static char MAN = 'P';
    private static char TABLE = 'O';
    private static char PARTITION = 'X';
    private static int OBEY = 1;
    private static int NOT_OBEY = 0;
    
    // 대기실 별로 지켰는지?
    // 겨우 125칸
    // bfs로 2칸 이하인데 O없는 X있는지? + 파티션 있는지?
    // 매번 찾아도 시간이 남아돈다.
    int[] dy = { 0, 0, 1, -1 };
    int[] dx = { 1, -1, 0, 0 };
    
    boolean isTwoManObeyRule(int y, int x, int nextY, int nextX, String[] place) {
        int yDistance = Math.abs(y - nextY);
        int xDistance = Math.abs(x - nextX);
        
        if (yDistance + xDistance == 1) {
            return false;
        }
        
        // 일직선상
        if (yDistance == 2) {
            return place[(y + nextY) / 2].charAt(x) == PARTITION;
        } else if (xDistance == 2) {
            return place[y].charAt((x + nextX) / 2) == PARTITION;
        } else {
            // 대각선
            return place[y].charAt(nextX) == PARTITION
                && place[nextY].charAt(x) == PARTITION;
        }
    }
    
    boolean isPointObeyRule(int y, int x, String[] place) {
        int height = place.length;
        int width = place[0].length();
        
        boolean[][] check = new boolean[height][width];
        
        Queue<Point> queue = new LinkedList<>();
        queue.add(new Point(y, x));
        check[y][x] = true;
        
        // 거리 2 넘으면 갈 필요 X
        // 발견했는데 1이면 무조건 
        while (!queue.isEmpty()) {
            Point point = queue.poll();
            int yNow = point.y;
            int xNow = point.x;
            
            if (Math.abs(y - yNow) + Math.abs(x - xNow) == 2) {
                continue;
            }
            
            for (int i = 0; i < 4; i++) {
                int nextY = yNow + dy[i];
                int nextX = xNow + dx[i];
                
                if (nextY < 0 || height <= nextY || nextX < 0 || width <= nextX) continue;
                if (check[nextY][nextX]) continue;
                
                if (place[nextY].charAt(nextX) == MAN 
                    && !isTwoManObeyRule(y, x, nextY, nextX, place)) {
                    return false;
                }
                
                check[nextY][nextX] = true;
                queue.add(new Point(nextY, nextX));
            }   
        }
        
        return true;
    }
    
    int checkPlaceObeyRule(String[] place) {
        for (int y = 0; y < place.length; y++) {
            for (int x = 0; x < place[y].length(); x++) {
                char point = place[y].charAt(x);
                if (point != MAN) {
                    continue;
                }
                
                if (!isPointObeyRule(y, x, place)) {
                    return NOT_OBEY;
                }
            }
        }
        
        return OBEY;
    }
    
    public int[] solution(String[][] places) {
        
        int[] answer = new int[places.length];
        for (int i = 0; i < places.length; i++) {
            answer[i] = checkPlaceObeyRule(places[i]);
        }
        
        return answer;
    }
    
    static class Point {
        int y;
        int x;
        Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
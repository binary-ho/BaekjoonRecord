class Solution {
    
    int n, m, r, c, k, y, x;
    int[] dy = {1, 0, 0, -1};
    int[] dx = {0, -1, 1, 0};
    char[] dir = {'d', 'l', 'r', 'u'};
    // d, l, r, u
    // 아래, 왼, 오, 위
    String ans = "z";
    
    private boolean check(int y, int x, int left)   {
        int yy = r - y;
        int xx = c - x;
        
        if (yy < 0) {
            yy *= -1;
        }
        if (xx < 0) {
            xx *= -1;
        }
        
        int move = yy + xx;
        if (left < move || (left - move) % 2 == 1) return false;
        return true;
    }
    public String solution(int _n, int _m, 
                           int y, int x, 
                           int _r, int _c, int k) {
        n = _n; m = _m;
        r = _r; c = _c;
        
        if(!check(y, x, k)) return "impossible";

        dfs(k, y, x, new StringBuilder());
        return ans;
    }
    
    private void dfs(int move, int y, int x, StringBuilder str) {
        if (ans.compareTo(str.toString()) < 0
           || !check(y, x, move)) {
            return;
        }
        
        if (move == 0) {
            if (y == r && x == c) {
                ans = str.toString();
            }
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if (nextY < 1 || nextY > n || nextX < 1 || nextX > m) {
                continue;
            }
            
            dfs(move - 1, nextY, nextX, str.append(dir[i]));
            str.delete(str.length() - 1, str.length());
        }
    }
}
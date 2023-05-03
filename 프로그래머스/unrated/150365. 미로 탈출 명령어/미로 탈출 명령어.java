class Solution {
    
    int n, m, r, c, k, y, x;
    int[] dy = {1, 0, 0, -1};
    int[] dx = {0, -1, 1, 0};
    char[] dir = {'d', 'l', 'r', 'u'};
    // d, l, r, u
    // 아래, 왼, 오, 위
    String ans = "z";
    
    private boolean check(int yy, int xx, int left)   {
        int yyy = r - yy;
        int xxx = c - xx;
        
        if (yyy < 0) {
            yyy *= -1;
        }
        if (xxx < 0) {
            xxx *= -1;
        }
        
        int move = yyy + xxx;
        if (left < move) return false;
        
        yyy = y - yy;
        xxx = x - xx;
        if (yyy < 0) {
            yyy *= -1;
        }
        if (xxx < 0) {
            xxx *= -1;
        }
        
        move += yyy + xxx;
        if (k < move || (k - move) % 2 == 1) return false;
        return true;
    }
    public String solution(int _n, int _m, 
                           int _y, int _x, 
                           int _r, int _c, int _k) {
        n = _n; m = _m;
        y = _y; x = _x;
        r = _r; c = _c;
        k = _k;
        
        if(!check(y, x, k)) return "impossible";

        // updateMin();
        
        dfs(k, y, x, new StringBuilder());
        if (ans.equals("z")) {
            return "impossible";
        }
        
        return ans;
    }
    
    private void updateMin() {
        StringBuilder temp = new StringBuilder();
        int down = r - y;
        while(down > 0) {
            down--;
            temp.append('d');            
        }
        
        int left = x - c;
        while (left > 0) {
            left--;
            temp.append('l');
        }
        
        while (left < 0) {
            left++;
            temp.append('r');
        }
        
        while (down < 0) {
            down++;
            temp.append('d');
        }
        
        // dlru
        int c1, c2;
        if (temp.length() < k) {
            if (r < n) {
                c1 = 0;
                c2 = 3;
            } else if (c > 1) {
                c1 = 1;
                c2 = 2;
            } else if (c < m) {
                c1 = 2;
                c2 = 1;
            } else {
                c1 = 3;
                c2 = 0;
            }
            // 아래 위가 제일 유리하다
            // 왼오
            // 오왼
            // 위아래
            
            int cnt = k - temp.length();
            
            // 움직일 수 있는 만큼 움직인다.
            int yy = r;
            int xx = c;
            // cnt는 더 채워야 할 갯수
            while (cnt > 0) {
                int cnt2 = cnt / 2;
                int cnt3 = 0;
                while(1 <= yy && yy <= n
                     && 1 <= xx && xx <= m
                     && cnt2 > 0) {
                    cnt2--;
                    cnt3++;
                    yy += dy[c1];
                    xx += dx[c1];
                    temp.append(dir[c1]);
                }
                
                cnt -= cnt3*2;
                
                while (1 <= yy && yy <= n
                     && 1 <= xx && xx <= m
                     && cnt3 > 0) {
                    cnt3--;
                    yy += dy[c2];
                    xx += dx[c2];
                    temp.append(dir[c2]);
                }
            }
        }
        
        ans = temp.toString();
    }
    
    private void dfs(int move, int yy, int xx, StringBuilder str) {
        if (ans.compareTo(str.toString()) < 0
           || !check(yy, xx, move)) {
            return;
        }
        
        if (move == 0) {
            if (yy == r && xx == c) {
                ans = str.toString();
            }
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            // 검증
            int nextY = yy + dy[i];
            int nextX = xx + dx[i];
            if (nextY < 1 || nextY > n || nextX < 1 || nextX > m) {
                continue;
            }
            
            dfs(move - 1, nextY, nextX, str.append(dir[i]));
            str.delete(str.length() - 1, str.length());
        }
    }
}
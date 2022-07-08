import java.util.*;

class Pos {
    int r, c;
    public Pos(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

public class Main {
    static int ans = 100;
    static int testTest = 100;
    static int zSize;
    static List<Pos> z = new ArrayList<>();
    static int[][] s = new int[5][5];
    static boolean[][] v = new boolean[5][5];
    static int[] dr = {0, 0, 1, -1};
    static int[] dc = {1, -1, 0, 0};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            String l = sc.nextLine();
            for (int j = 0; j < 5; j++) {
                if (l.charAt(j) == '*') {
                    z.add(new Pos(i, j));
                }
            }
        }
        zSize = z.size();
        fill(0, new ArrayList<>());

        System.out.println(ans);
    }

    static void fill(int idx, List<Pos> l) {
        if (l.size() == zSize) {
            for (Pos p : l) s[p.r][p.c] = 1;
            boolean b = chk(l.get(0).r, l.get(0).c);
            if(b) {
                testTest = 100;
                per(0, new ArrayList<>(), l);
                ans = min(ans, testTest);
            }
            for (Pos p : l) s[p.r][p.c] = 0;
            return;
        }
        if (idx == 25) {
            return;
        }
        l.add(new Pos(idx / 5, idx % 5));
        fill(idx + 1, l);
        l.remove(l.size() - 1);
        fill(idx + 1, l);
    }

    static void dist(List<Integer> st, List<Pos> l) {
        int ret = 0;
        for (int i = 0; i < z.size(); i++) {
            Pos p1 = z.get(i);
            Pos p2 = l.get(st.get(i));
            ret += abs(p1.r - p2.r) + abs(p1.c - p2.c);
        }
        if(testTest > ret) {
            testTest = ret;
        }
    }

    static boolean chk(int r, int c) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                v[i][j] = false;
            }
        }

        Queue<Pos> q = new LinkedList<>();
        q.offer(new Pos(r, c));
        v[r][c] = true;
        int cnt = 1;
        while (!q.isEmpty()) {
            Pos p = q.poll();
            for (int d = 0; d < 4; d++) {
                int nr = p.r + dr[d], nc = p.c + dc[d];
                if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5) continue;
                if (v[nr][nc]) continue;
                if (s[nr][nc] == 0) continue;
                v[nr][nc] = true;
                q.offer(new Pos(nr, nc));
                cnt++;
            }
        }

        return cnt == z.size();
    }

    static int abs(int n) {
        return n > 0 ? n : -n;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }
    static void per(int idx, List<Integer> st, List<Pos> l) {
        if(idx == zSize) {
            dist(st, l);
            return;
        }
        for(int i = 0; i < zSize; i++) {
            if(st.contains(i)) continue;
            st.add(i);
            per(idx + 1, st, l);
            st.remove(st.size() - 1);
        }
    }
}
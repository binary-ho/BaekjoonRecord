import java.util.*;


class Solution {

    final int SIZE = 2602; 
    // 패런트 배열과 rank가 필요
    int[] parent = new int[SIZE];
    Cell[] table = new Cell[SIZE];
    
    public String[] solution(String[] commands) {
        ArrayList<String> ans = new ArrayList<>();
        for (int i = 0; i < SIZE; i++) {
            parent[i] = i;
            table[i] = new Cell();
        }
        
        for (String command : commands) {
            String[] strs = command.split(" ");
            switch (strs[0]) {
                case "UPDATE": 
                    if (strs.length == 3) {
                        updateValNewVal(strs[1], strs[2]);
                    } else {
                        updateValByAxis(strs[1], strs[2], strs[3]);
                    }
                    break;
                case "MERGE": merge(strs[1], strs[2], strs[3], strs[4]); break;
                case "UNMERGE": unmerge(strs[1], strs[2]); break;
                case "PRINT": 
                ans.add(print(strs[1], strs[2])); break;
                default: break;
            }
        }
        
        String[] answer = ans.toArray(new String[ans.size()]);
        return answer;
    }
    
    class Cell {
        String val;
        Cell() {
            this.val = null;
        }
    }
    
    private int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    private boolean union(int _u, int _v) {
        int u = find(_u);
        int v = find(_v);
        if (u == v) {
            return false;
        }
        
        int vv = parent[v];
        for (int  i = 0; i < SIZE; i++) {
            if (parent[i] != vv) {
                continue;
            }
            parent[i] = u;
        }
        return true;
    }
    
    private void updateValByAxis(String r, String c, String newValue) {
        int ax = parent[axis(r, c)];
        table[ax].val = newValue;       
    }
    
    private void updateValNewVal(String val1, String val2) {
        for (int i = 0; i < SIZE; i++) {
            if (!val1.equals(table[i].val)) {
                continue;
            }
            
            table[i].val = val2;
        }
    }
    
    private String print(String r, String c) {
        // 안 될 수도 있다. 부모가 가진 값을 반환해야 할 수도 있다.
        int ax = axis(r, c);
        if (parent[ax] != ax) {
            ax = parent[ax];
        }
        return table[ax].val != null
        ? table[ax].val 
        : "EMPTY";
    }
    
    private void merge(String r1, String c1, String r2, String c2) {
        System.out.println("MERGE " + r1 + ", " + c1 
                           + " // " + r2 +", " + c2);
        int ax1, ax2;
        ax1 = axis(r1, c1); ax2 = axis(r2, c2);
        if (find(ax1) == find(ax2)) return;
        
        String val;
        if (table[parent[ax1]].val != null) {
            val = table[parent[ax1]].val;
        } else {
            val = table[parent[ax2]].val;
        }
        table[ax1].val = table[ax2].val = val;
            
        union(ax1, ax2);
        System.out.println("find : " + find(ax1) + ", " + find(ax2));
        System.out.println("vals : " + table[ax1].val + ", " + table[ax2].val);
    }
    
    private void unmerge(String r, String c) {
        int ax = axis(r, c);
        int kill = parent[ax];
        System.out.println("UNMERGE : " + r + ", " + c + "의 부모 " + kill);
        String val = table[kill].val;
        
        for (int i = 0; i < SIZE; i++) {
            if (parent[i] != kill) {
                continue;
            }
            parent[i] = i;
            table[i].val = null;
            System.out.println("UNMERGE : " + i);
        }
        table[ax].val = val;
    }
    
    private int axis(String r, String c) {
        return (Integer.parseInt(r) - 1) * 50 + Integer.parseInt(c) - 1;
    }
}
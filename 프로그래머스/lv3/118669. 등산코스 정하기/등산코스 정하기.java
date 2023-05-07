import java.util.*;

class Solution {
    
    private static int nn;
    private static int bongCnt;
    private static ArrayList<Point>[] arr;
    private static int[] ch;
    private static int[] gg;
    private static int[] ss;
    
    int tmpIntensity;
    int bong = 50001;
    int intensity = 10000000;
    private static class Point {
        int n;
        int d;
        
        Point(int n, int d) {
            this.n = n;
            this.d = d;
        }
    }
    
    public void dikstra(int v) {
        
        if (intensity < ch[v]) return;
        
        for(int i=0; i<arr[v].size(); i++) {
            int nx = arr[v].get(i).n; int nd = arr[v].get(i).d;
            if (gg[nx] == 1) continue;
            if (ch[nx] == 0
                || (ch[nx] != 0 && (ch[v] < nd ? nd : ch[v]) < ch[nx])) {
                
                ch[nx] = ch[v] < nd ? nd : ch[v];
                if (ss[nx] == 1) {
                    if (ch[nx] < intensity) {
                        bong = nx;
                        intensity = ch[nx];
                    }
                    else if (ch[nx] == intensity && nx < bong) {
                        bong = nx;
                    }
                    continue;
                }
                dikstra(nx);
            }
        }
    }
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        nn = n+1;
        bongCnt = summits.length;
        
        arr = new ArrayList[nn];
        ch = new int[nn];
        gg = new int[nn];
        ss = new int[nn];
        
        
        for(int i=1; i<=n; i++) {
            arr[i] = new ArrayList<Point>();
        }
        for(int i=0; i<gates.length; i++) {
            gg[gates[i]] = 1;
        }
        for(int i=0; i<summits.length; i++) {
            ss[summits[i]] = 1;
        }
        
        int minGate = 0, minCost = 10_000_001;
        for(int i=0; i<paths.length; i++) {
            int n1 = paths[i][0]; int n2 = paths[i][1]; int d = paths[i][2];
            arr[n1].add(new Point(n2, d));
            arr[n2].add(new Point(n1, d));
            if (gg[n1] == 1 && minCost > d) {
                minGate = n1;
                minCost = d;
            } else if (gg[n2] == 1 && minCost > d) {
                minGate = n2;
                minCost = d;
            }
        }
        
        dikstra(minGate);
        for(int i: gates) {
            dikstra(i);
        }
        for(int j=0; j<summits.length; j++) {
            if (ch[summits[j]] != 0 && ch[summits[j]] < intensity) {
                bong = summits[j];
                intensity = ch[summits[j]];
            }
            else if (ch[summits[j]] == intensity && summits[j] < bong) {
                bong = summits[j];
            }
        }
        int[] ans = new int[2];
        ans[0] = bong; ans[1] = intensity;
        return ans;
    }
}
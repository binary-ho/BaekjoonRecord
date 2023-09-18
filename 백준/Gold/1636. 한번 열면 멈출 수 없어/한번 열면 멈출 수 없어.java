import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

class Main {

    static Range[] ranges;
    static int[][] sum;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        ranges = new Range[N];
        sum = new int[N][201];

        for (int i = 0; i < N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int s = Integer.parseInt(stringTokenizer.nextToken());
            int e = Integer.parseInt(stringTokenizer.nextToken());
            ranges[i] = new Range(s, e);
        }

//        for (int i = prings[0].s; i <= prings[0].e; i++) {
//
//        }
        for (int i = 1; i < N; i++) {
            Range now = ranges[i];
            Range prev = ranges[i - 1];
            for (int j = now.s; j <= now.e; j++) {
                if (j < prev.s) {
                    sum[i][j] = sum[i - 1][prev.s] + (prev.s - j);
                } else if (j > prev.e) {
                    sum[i][j] = sum[i - 1][prev.e] + (j - prev.e);
                } else {
                    // 포함
                    sum[i][j] = sum[i - 1][j];
                }
            }
        }

        Range last = ranges[N - 1];
        int lastIndex = last.s;
        int lastStress = sum[N - 1][lastIndex];
        for (int i = last.s + 1; i <= last.e; i++) {
            if (lastStress > sum[N - 1][i]) {
                lastStress = sum[N - 1][i];
                lastIndex = i;
            }
        }

        System.out.println(lastStress);
        // 역추적 인덱스를 출력하라
        // 겹친다 그대로 올라가
        // 안 겹친다 최소 이동
        Stack<Integer> st = new Stack<>();
        st.push(lastIndex);
        for (int depth = N - 2; depth >= 0; depth--) {
            Range now = ranges[depth];

            if (lastIndex < now.s) {
                lastIndex = now.s;
            } else if (now.e < lastIndex){
                lastIndex = now.e;
            }

            st.push(lastIndex);
        }

        while(!st.isEmpty()) {
            int indexNow = st.pop();
            System.out.println(indexNow);
        }
    }

    static class Range {
        int s;
        int e;
        Range(int s, int e) {
            this.s = s;
            this.e = e;
        }
    }
}



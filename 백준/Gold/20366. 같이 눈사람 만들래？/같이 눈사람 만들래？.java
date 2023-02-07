import static java.lang.Math.abs;
import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] snow;
    static Snow[] snowMan;
    static long ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        snow = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            snow[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(snow);

        int N2 = N * (N - 1) / 2;
        snowMan = new Snow[N2];

        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                snowMan[idx++] = new Snow(snow[i] + snow[j], i, j);
            }
        }

        Arrays.sort(snowMan);
        ans = 1000000001;
        idx = -1;
        while (++idx < N2 - 1) {
            if (snowMan[idx].contains(snowMan[idx + 1])) {
                continue;
            }
            ans = min(ans, abs(snowMan[idx].height - snowMan[idx + 1].height));
        }
        System.out.println(ans);
    }

    static class Snow implements Comparable{
        public int height, snow1, snow2;

        public Snow(int height, int snow1, int snow2) {
            this.height = height;
            this.snow1 = snow1;
            this.snow2 = snow2;
        }

        boolean contains(Snow snow) {
            if (snow.snow1 == this.snow1 || snow.snow1 == this.snow2 || snow.snow2 == this.snow1 || snow.snow2 == this.snow2) return true;
            return false;
        }

        @Override
        public int compareTo(Object o) {
            Snow snow = (Snow) o;
            if (height < snow.height) {
                return -1;
            } else if (height > snow.height) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int left, right, max;
    static int[] power;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        power = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            power[i] = Integer.parseInt(st.nextToken());
        }

        left = 0;
        right = N - 1;
        max = 0;
        while (left < right) {
            max = max((right - left - 1) * min(power[left], power[right]), max);
            if (power[left] < power[right]) {
                left++;
            } else {
                right--;
            }
        }

        System.out.println(max);
    }
}
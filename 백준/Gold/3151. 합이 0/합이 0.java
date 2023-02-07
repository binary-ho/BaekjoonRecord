import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] codingPower;
    static int left, right, standard, sum;
    static int leftTemp, rightTemp, leftCnt, rightCnt;
    static long ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        codingPower = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            codingPower[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(codingPower);
        ans = 0;
        for (standard = 0; standard + 2 < N; ++standard) {
            left = standard + 1; right = N - 1;

            while (left < right) {
                sum = codingPower[standard] + codingPower[left] + codingPower[right];
                if (sum == 0) {
                    if (codingPower[left] != codingPower[right]) {
                        leftTemp = codingPower[left];
                        rightTemp = codingPower[right];

                        leftCnt = rightCnt = 0;
                        while (leftTemp == codingPower[left]) {
                            left++;
                            leftCnt++;
                        }

                        while (rightTemp == codingPower[right]) {
                            right--;
                            rightCnt++;
                        }
                        ans += (long) leftCnt * rightCnt;
                    } else {
                        ans += right - left;
                        left++;
                    }
                } else if (sum > 0) {
                    right--;
                } else  {
                    left++;
                }
            }
        }
        System.out.println(ans);
    }
}

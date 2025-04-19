
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    /*
    * 세는건 무조건 말이 안돼
    * k번째까지 봤을 때 어떤 숫자 X를 만드는 가짓수를 셀 수 있나? 그 K가 1000 밖에 안돼
    * 의외로 1000 * 50만에 될 수도?
    * */
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        final int N = Integer.parseInt(stringTokenizer.nextToken());
        final int M = Integer.parseInt(stringTokenizer.nextToken());
        final int H = Integer.parseInt(stringTokenizer.nextToken());

        final List<Integer>[] studentsBlock = new LinkedList[N];
        for (int i = 0; i < N; i++) {
            studentsBlock[i] = new LinkedList<>();
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            while (stringTokenizer.hasMoreTokens()) {
                studentsBlock[i].add(Integer.parseInt(stringTokenizer.nextToken()));
            }
        }

        // 첫 원소 채우기
        final int[][] made = new int[N][H + 1];
        made[0][0]++;
        for (int block : studentsBlock[0]) {
            made[0][block]++;
        }

        final int DIV = 10_007;
        for (int i = 1; i < N; i++) {
            List<Integer> blocks = studentsBlock[i];
            made[i][0]++;
            for (int h = 1; h <= H; h++) {
                made[i][h] = made[i - 1][h];

                for (int block : blocks) {
                    // 이 숫자를 만들 수 있냐?
                    if (h - block >= 0) {
                        made[i][h] += made[i - 1][h - block];
                        made[i][h] %= DIV;
                    }
                }
            }

//            System.out.println(i + " ====================");
//            for (int h = 1; h <= H; h++) {
//                if (made[i][h] > 0) {
//                    System.out.println(h + " -> " + made[i][h]);
//                }
//            }
        }
        System.out.println(made[N - 1][H] % DIV);
    }
}


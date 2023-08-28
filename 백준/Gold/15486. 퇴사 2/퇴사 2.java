import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        int N;
        N = Integer.parseInt(stringTokenizer.nextToken());

        int[] T = new int[N + 2];
        int[] P = new int[N + 2];
        for (int day = 1; day <= N; day++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            T[day] = Integer.parseInt(stringTokenizer.nextToken());
            P[day] = Integer.parseInt(stringTokenizer.nextToken());
        }

        // 오늘까지 얼마 벌었다를 체크하는거 어때?? 좋은듯
        int TOTAL_DAY = 1_500_051;
        long[] totalProfit =  new long[TOTAL_DAY];
        // 며칠에 얼마 며칠에 얼마

        long maxProfit = 0;
        for (int day = 1; day <= N + 1; day++) {
            long dayProfit = Math.max(totalProfit[day], maxProfit);
            
            if (totalProfit[day + T[day]] < dayProfit + P[day]) {
                totalProfit[day + T[day]] = dayProfit + P[day];
            }

            if (maxProfit < totalProfit[day]) {
                maxProfit = totalProfit[day];
            }
        }

        // 건너뛸 수가 있어야해 
        System.out.println(maxProfit);
    }
}

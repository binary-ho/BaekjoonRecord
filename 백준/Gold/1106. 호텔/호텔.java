
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

    // 적어도 C명 늘리기 위해 얼마나 필요한가?
    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        int C, N;
        C = Integer.parseInt(stringTokenizer.nextToken());
        N = Integer.parseInt(stringTokenizer.nextToken());

        int[] costs = new int[N];
        int[] plus = new int[N];
        int[] customerCost = new int[1100];

        int INF = 987654321;
        Arrays.fill(customerCost, INF);

        for (int index = 0; index < N; index++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            costs[index] = Integer.parseInt(stringTokenizer.nextToken());
            plus[index] = Integer.parseInt(stringTokenizer.nextToken());
            if (customerCost[plus[index]] > costs[index]) {
                customerCost[plus[index]] = costs[index];
            }
        }

        for (int customer = 0; customer < 1100; customer++) {
            for (int index = 0; index < N; index++) {
                // 정렬하면 break로 줄이기도 가능
                if (customer < plus[index]) continue;
                if (customerCost[customer] <= customerCost[customer - plus[index]] + costs[index]) continue;
                customerCost[customer] = customerCost[customer - plus[index]] + costs[index];
            }
        }

        int answer = INF;
        for (int index = C; index < 1100; index++) {
            if (answer > customerCost[index]) {
                answer = customerCost[index];
            }
        }
        System.out.println(answer);
    }
}



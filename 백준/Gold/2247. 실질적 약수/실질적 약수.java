import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        int N = Integer.parseInt(stringTokenizer.nextToken());

        long NN = N / 2;
        long sum = 0;

        for (int i = 2; i <= NN; i++) {
            int div = N / i - 1;
            sum += ((long) div * i);
            sum %= 1000000;
        }
        System.out.println(sum);
    }
}


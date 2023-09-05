

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    static int[][] sendTime = new int[13][13];
    static boolean[] groupCheck = new boolean[7];
    static int answer = 12001;
//    static int totalTime = 0;
    
    
    // 2로 나누면 team Number
    public static void go(int studentNow, int totalTime, int depth) {
        int friendsBias = studentNow % 2 == 0 ? 1 : -1;

        if (depth == 6) {
            answer = Math.min(answer, totalTime + sendTime[studentNow][studentNow + friendsBias]);
            return;
        }


        for (int i = 0; i < 6; i++) {
            if (groupCheck[i]) continue;
            groupCheck[i] = true;
            for (int j = 0; j < 2; j++) {
                int studentNext = i * 2 + j;
                go(studentNext,
                    totalTime + sendTime[studentNow][studentNow + friendsBias] + sendTime[studentNow + friendsBias][studentNext],
                    depth + 1);
            }
            groupCheck[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 12; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            for (int j = 0; j < 12; j++) {
                sendTime[i][j] = Integer.parseInt(stringTokenizer.nextToken());
            }
        }

        for (int i = 0; i < 6; i++) {
            groupCheck[i] = true;
            for (int j = 0; j < 2; j++) {
                int studentNext = i * 2 + j;
                go(studentNext,  0, 1);
            }
            groupCheck[i] = false;
        }

        System.out.println(answer);
    }
}



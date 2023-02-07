import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N, X;
    static int left, right, ans;
    static int[] S;
    static Map<Integer, Integer> map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        S = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            S[i] = Integer.parseInt(st.nextToken());
        }

        map = new HashMap<>();
        left = right = ans = 0;
        Integer temp;
        while (right < N && left <= right) {
            temp = map.get(S[right]);

            if (temp == null || temp < X) {
                putKey(S[right++]);
            } else {
                popKey(S[left++]);
            }
            if (ans < right - left) ans = right - left;
        }

        System.out.println(ans);
    }

    public static void putKey(int key) {
        if (map.containsKey(key)) {
            map.put(key, map.get(key) + 1);
        } else {
            map.put(key, 1);
        }
    }

    public static void popKey(int key) {
        Integer cnt = map.get(key);
        if (cnt == 1) {
            map.remove(key);
        } else {
            map.put(key, map.get(key) - 1);
        }
    }
}
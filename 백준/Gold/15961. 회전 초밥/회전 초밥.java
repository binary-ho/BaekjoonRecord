import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N, d, k, c;
    static int[] sushi;
    static Map<Integer, Integer> sushiMap;
    static int left = 0, right = 0;
    static int keyNow, cntNow, maxCnt;
    static Integer valueNow;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        sushi = new int[N];

        for (int i = 0; i < N; i++) {
            sushi[i] = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
        }

        sushiMap = new HashMap<>();
        while (right < k) {
            keyNow = sushi[right++];
            putValueByKey(keyNow);
        }
        cntNow = maxCnt = sushiMap.size();

        while (left < N) {
            if (right == N) {
                right = 0;
            }
            putValueByKey(sushi[right++]);
            removeValueByKey(sushi[left++]);
            cntNow = sushiMap.size();
            couponCheck();
            if (maxCnt < cntNow) maxCnt = cntNow;
        }

        System.out.println(maxCnt);
    }

    static void putValueByKey(int key) {
        Integer value = sushiMap.get(key);
        if (value == null) {
            sushiMap.put(key, 1);
            return;
        }
        sushiMap.put(key, value + 1);
    }

    static void removeValueByKey(Integer key) {
        Integer value = sushiMap.get(key);
        if (value == 1) {
            sushiMap.remove(key);
            return;
        }
        sushiMap.put(key, value - 1);
    }

    static void couponCheck() {
        if (sushiMap.get(c) == null) {
            cntNow++;
        }
    }
}

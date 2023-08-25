
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

class Main {

    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        n = Integer.parseInt(stringTokenizer.nextToken());
        m = Integer.parseInt(stringTokenizer.nextToken());

        int command, a, b;
        Union union = new Union(n);
        while (m-- > 0) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            command = Integer.parseInt(stringTokenizer.nextToken());
            a = Integer.parseInt(stringTokenizer.nextToken());
            b = Integer.parseInt(stringTokenizer.nextToken());

            if (command == 0) {
                union.union(a, b);
                continue;
            }

            if (union.isUnion(a, b)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    // 배열을 넣으면 연산 지원??
    // 애초에 갖고 있는 집합이 딱 있어야 한다.
    static class Union {

        int[] parent;

        Union(int n) {
            parent = IntStream
                .range(0, n + 2)
                .toArray();
        }

        public int find(int a) {
            if (a == parent[a]) {
                return a;
            }

            return parent[a] = find(parent[a]);
        }

        public boolean isUnion(int a, int b) {
            return find(a) == find(b);
        }

        public void union(int a, int b) {
            int aParent = find(a);
            parent[aParent] = find(b);
        }
    }
}



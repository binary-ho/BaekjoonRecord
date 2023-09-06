
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;

class Main {

    static int NODE_SIZE = 10001;
    static List<List<Node>> edges = new ArrayList<>();
    static int[] route = new int[11];
    static long V, E, INF = 98_765_432_1000L;
//100억

    static long[] myMap = new long[NODE_SIZE];
    static long[] yMap = new long[NODE_SIZE];

    static class Node {
        int number;
        long dist;
        Node(int number, long dist) {
            this.number = number;
            this.dist = dist;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        V = Integer.parseInt(stringTokenizer.nextToken());
        E = Integer.parseInt(stringTokenizer.nextToken());

        for (int i = 0; i <= V; i++) {
            edges.add(new ArrayList<>());
        }

        int u, v, w;
        for (int i = 0; i < E; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            u = Integer.parseInt(stringTokenizer.nextToken());
            v = Integer.parseInt(stringTokenizer.nextToken());
            w = Integer.parseInt(stringTokenizer.nextToken());

            edges.get(u).add(new Node(v, w));
            edges.get(v).add(new Node(u, w));
        }

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        for (int i = 0; i < 10; i++) {
            route[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        // 내 이동
        PriorityQueue<Node> queue = new PriorityQueue<>((Node n1, Node n2) -> {
            if (n1.dist > n2.dist) {
                return 1;
            }
            return -1;
        });

        for (int i = 0; i <= V; i++) {
            myMap[i] = INF;
        }

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int start = Integer.parseInt(stringTokenizer.nextToken());
        myMap[start] = 0;
        queue.add(new Node(start, 0));

        while (!queue.isEmpty()) {
            Node nodeNow = queue.poll();
            if (myMap[nodeNow.number] < nodeNow.dist) continue;

            for (Node nextNode : edges.get(nodeNow.number)) {
                if (myMap[nextNode.number] < nodeNow.dist + nextNode.dist) continue;

                myMap[nextNode.number] = nodeNow.dist + nextNode.dist;
                queue.add(new Node(nextNode.number, nodeNow.dist + nextNode.dist));
            }
        }

        // 아주머니가 이동하면서 후보들 체크
        // 갈 수 있는지 체크하면서, 갈 수 있으면 가고 못 가면 안 가고, 순서를 지키면서 이동

        long answer = INF;
        start = route[0];
        
        long total = 0L;
        for (int i = 1; i < 10; i++) {
            int destination = route[i];

            for (int k = 0; k <= V; k++) {
                yMap[k] = INF;
            }

            yMap[start] = 0;
            queue.add(new Node(start, 0));
            if (myMap[start] <= total) {
                answer = Math.min(answer, start);
            }

            while (!queue.isEmpty()) {
                Node nodeNow = queue.poll();
                if (yMap[nodeNow.number] < nodeNow.dist) continue;

                for (Node nextNode : edges.get(nodeNow.number)) {
                    if (yMap[nextNode.number] < nodeNow.dist + nextNode.dist) continue;

                    yMap[nextNode.number] = nodeNow.dist + nextNode.dist;
                    queue.add(new Node(nextNode.number, nodeNow.dist + nextNode.dist));
                }
            }

            if (yMap[destination] == INF) continue;
            start = destination;
            total += yMap[destination];
            
            if (myMap[destination] <= total) {
                answer = Math.min(answer, destination);
            }
        }

        System.out.println(answer == INF ? -1 : answer);
    }
}



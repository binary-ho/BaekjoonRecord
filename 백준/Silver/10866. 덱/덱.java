import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static int N, appendInt;
    static String command;
    static LinkedList<Integer> linkedList;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder stringBuilder = new StringBuilder();

        N = Integer.parseInt(st.nextToken());

        linkedList = new LinkedList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            command = st.nextToken();
            if (command.charAt(0) == 's') {
                appendInt = linkedList.size();
            } else if (command.charAt(0) == 'e') {
                appendInt = linkedList.isEmpty() ? 1 : 0;
            } else if (command.charAt(0) == 'f') {
                if (linkedList.isEmpty()) {
                    appendInt = -1;
                } else {
                    appendInt = linkedList.peekFirst();
                }
            } else if (command.charAt(0) == 'b') {
                if (linkedList.isEmpty()) {
                    appendInt = -1;
                } else {
                    appendInt = linkedList.peekLast();
                }

            } else if (command.charAt(5) == 'f') {
                linkedList.addFirst(Integer.parseInt(st.nextToken()));
                continue;
            } else if (command.charAt(5) == 'b') {
                linkedList.addLast(Integer.parseInt(st.nextToken()));
                continue;
            } else if (command.charAt(4) == 'f') {
                if (linkedList.isEmpty()) {
                    appendInt = -1;
                } else {
                    appendInt = linkedList.pollFirst();
                }
            } else {
                if (linkedList.isEmpty()) {
                    appendInt = -1;
                } else {
                    appendInt = linkedList.pollLast();
                }
            }
            stringBuilder.append(appendInt + "\n");
        }
        System.out.println(stringBuilder);
    }
}

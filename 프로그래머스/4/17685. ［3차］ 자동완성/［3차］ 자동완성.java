import java.util.*;

class Solution {
    
    public int solution(String[] words) {
        
        Node root = new Node();
        root.count = 0;
        
        // 채우기
        for (String word : words) {
            Node trace = root;
            for (int i = 0; i < word.length(); i++) {
                char charNow = word.charAt(i);
                trace = trace.getIfPresentPutIfAbsent(charNow);
            }
            trace.isTerminal = true;
        }
        
        // 확인하기. 1이거나 해당 문자가 끝나면 종결
        int answer = 0;
        for (String word : words) {
            Node trace = root;
            
            for (int i = 0; i < word.length(); i++) {
                char charNow = word.charAt(i);
                trace = trace.child.get(charNow);
                
                answer++;
                
                if (trace.count == 1) {
                    break;
                }
            }
        }
        
        return answer;
    }
    
    class Node {
        boolean isTerminal;
        int count;
        Map<Character, Node> child;
        
        Node() {
            this.isTerminal = false;
            this.child = new HashMap<>();
            this.count = 1;
        }
        
        void increase() {
            count++;
        }
        
        Node getIfPresentPutIfAbsent(char ch) {
            Node next = child.get(ch);
            if (next == null) {
                child.put(ch, new Node());
            } else {
                next.count++;
            }
            return child.get(ch);
        }
    }
}
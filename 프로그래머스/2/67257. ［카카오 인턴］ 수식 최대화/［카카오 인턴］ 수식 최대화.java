import java.util.*;
import java.util.stream.*;

class Solution {
    
    long answer = 0;
    String[] operations = {"\\*", "\\+", "-"};
    
    String convertRawOperation(String operation) {
        switch (operation) {
            case "\\*" : 
                return "*";
                
            case "\\+" : 
                return "+";
                
            default : 
                return "-";
        }
    }
    
    String getNewValue(String operation, String previousToken, String token) {
        Long previousValue = Long.parseLong(previousToken);
        Long value = Long.parseLong(token);
        
        switch (operation) {
            case "\\*" : 
                return String.valueOf(previousValue * value);
                
            case "\\+" : 
                return String.valueOf(previousValue + value);
                
            default : 
                return String.valueOf(previousValue - value);
        }
    }
    
    List<String> splitExpression(List<String> expressions, String delimiter) {
        LinkedList<String> tokens = new LinkedList<>();
        for (String expression : expressions) {
            if (!expression.contains(convertRawOperation(delimiter))) {
                tokens.add(expression);
                continue;
            }
            
            for (String token : expression.split(delimiter)) {
                tokens.add(token);
                tokens.add(delimiter);
            }
            tokens.pollLast();
        }
        
        return tokens;
    }
    
    long calculateExpression(Map<Integer, String> priority, String expression) {

        List<String> tokens = List.of(expression);
        for (String operation : operations) {
            tokens = splitExpression(tokens, operation);
        }
        
        LinkedList<String> tokensTemp;
        for (int i = 0; i < operations.length; i++) {
            tokensTemp = new LinkedList<>();
            String operation = priority.get(i);
            
            for (String token : tokens) {
                if (tokensTemp.isEmpty()
                    || (!tokensTemp.isEmpty()
                    && !tokensTemp.getLast().equals(operation))) {
                    
                    tokensTemp.add(token);
                    continue;
                }
                
                // 연산자 제거
                tokensTemp.pollLast();
                String previousToken = tokensTemp.pollLast();
                String newValue = getNewValue(operation, previousToken, token);
                tokensTemp.add(newValue);
            }
            
            tokens = List.copyOf(tokensTemp);
        }
        
        return Long.parseLong(tokens.get(0));
    }
    
    void dfs(int depth, Map<Integer, String> priority, String expression) {
        if (depth == operations.length) {
            long result = calculateExpression(priority, expression);
            if (answer < Math.abs(result)) {
                answer = Math.abs(result);
            }
            return;
        }
        
        for (String operation : operations) {
            if (priority.containsValue(operation)) {
                continue;
            }
            
            priority.put(depth, operation);
            dfs(depth + 1, priority, expression);
            priority.remove(depth);
        }
        return;
    }
    
    
    // 8:56
    public long solution(String expression) {
        Map<Integer, String> priority = new HashMap<>();
        dfs(0, priority, expression);
        // 음수면 변환
        return answer;
    }
}
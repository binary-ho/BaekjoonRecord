class Solution {
    
    // 4 : 25 ~
    public String solution(String newId) {
        // 1
        newId = newId.toLowerCase();
        
        // 2
        newId = step2(newId);

        // 3
        while (newId.indexOf("..") != -1) {
            newId = newId.replace("..", ".");
        }
        
        // 4
        if (newId.charAt(0) == '.') {
            newId = newId.substring(1);
        } 
        
        if (newId.length() > 0 && newId.charAt(newId.length() - 1) == '.') {
            newId = newId.substring(0, newId.length() - 1);
        }
        
        // 5단계
        if (newId.isEmpty()) {
            newId = "a";
        }
        
        // 6단계
        if (newId.length() >= 16) {
            System.out.println(newId);
            if (newId.charAt(14) == '.') {
                newId = newId.substring(0, 14);    
            } else {
                newId = newId.substring(0, 15);
            }
        }
        
        if (newId.length() <= 2) {
            while (newId.length() < 3) {
                newId += newId.charAt(newId.length() - 1);
            }
        }
        
        return newId;
    }
    
    String step2(String id) {
        int index = -1;
        StringBuilder stringBuilder = new StringBuilder(id);
        while (++index < stringBuilder.length()) {
            char charNow = stringBuilder.charAt(index);
            if ('a' <= charNow && charNow <= 'z') {
                continue;
            }
            
            if ('0' <= charNow && charNow <= '9') {
                continue;
            }
            
            if (charNow == '-' || charNow == '_' || charNow == '.') {
                continue;
            }
            
            stringBuilder.delete(index, index + 1);
            index--;
        }
        
        return stringBuilder.toString();
    }
}
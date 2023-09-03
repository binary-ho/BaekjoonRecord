class Solution {
    
    String answerWord;
    char[] chars = { 'A', 'E', 'I', 'O', 'U' }; 
    int count = 0;
    int answer = 0;
    StringBuilder word = new StringBuilder();
    
    void go() {
        if (answerWord.equals(word.toString())) {
            answer = count;
            return;
        }
        
        if (word.length() >= 5) {
            return;
        }
        
        int end = word.length();
        word.append('A');
        for (int i = 0; i < chars.length; i++) {
            word.replace(end, end + 1, String.valueOf(chars[i]));
            count++;
            go();
        }
        word.delete(end, end + 1);
        return;
    }
    
    public int solution(String word) {
        answerWord = word;
        go();
        
        return answer;
    }
}
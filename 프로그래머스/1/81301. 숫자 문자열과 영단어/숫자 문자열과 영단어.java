class Solution {
    
    String[] numbers = { "zero", "one", "two", "three", "four", 
                        "five", "six", "seven", "eight", "nine" };
    
    public int solution(String s) {
        
        for (int i = 0; i < numbers.length; i++) { 
            s = s.replaceAll(numbers[i], String.valueOf(i));
        }
        
        return Integer.valueOf(s);
    }
}
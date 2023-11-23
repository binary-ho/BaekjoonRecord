import java.util.*;
import java.util.stream.*;

class Solution {
    
    // 조합?
    // 최소 2요리 최소 2명한테 주문된 적 있는 조합
    // 2의 26제곱?
    // 26개중 10개를 뽑는다
    // 26^10
    int maxCourse = 0;
    Set<Integer> courses;
    List<Integer> orderBinaries = new LinkedList<>();
    
    List<Integer>[] answers = new LinkedList[11];
    int[] courseMaxCount = new int[11];
    
    // 얼마나 속해있는지 세야 한다.
    void countCombination(int combination, int course) {
        int count = 0;
        for (int order : orderBinaries) {
            int result = order & combination;
            if (result == combination) {
                count++;
            }
        }
        
        if (count == 0 || count == 1) {
            return;
        }
        
        // 초기화한다.
        if (courseMaxCount[course] < count) {
            courseMaxCount[course] = count;
            answers[course] = new LinkedList<>();
            answers[course].add(combination);
        } else if (courseMaxCount[course] == count) {
            answers[course].add(combination);
        }
        
        return;
    }
    
    
    void makeCombination(int courseCount, int idx, int combination) {
        if (courses.contains(courseCount)) {
            // 이제 세야한다.
            countCombination(combination, courseCount);
        }
        
        if (courseCount == maxCourse) {
            return;
        }
        
        for (int i = idx; i <= 26; i++) {
            makeCombination(courseCount + 1, i + 1, combination | (1 << i));
        }
    }
    
    void updateMaxCourse(int course) {
        if (maxCourse < course) {
            maxCourse = course;
        }
    }
    
    public String[] solution(String[] orders, int[] coursesOrigin) {
        
        courses = Arrays.stream(coursesOrigin)
            .peek(course -> updateMaxCourse(course))
            .boxed()
            .collect(Collectors.toSet());
        
        for (String order : orders) {
            int orderBinary = 0;
            for (int i = 0; i < order.length(); i++) {
                int numNow = order.charAt(i) - 'A';
                orderBinary |= (1 << numNow);
            }
            orderBinaries.add(orderBinary);
        }
        
        makeCombination(0, 0, 0);

        List<String> answersTemp = new LinkedList<>();
        for (int course : courses) {
            if (answers[course] == null) continue;
            for (Integer answerBinary : answers[course]) {
                answersTemp.add(getString(answerBinary));
            }
        }
        
        answersTemp.sort((s1, s2) -> {
            return s1.compareTo(s2);
        });
        
        return answersTemp
            .toArray(new String[answersTemp.size()]);
    }
    
    String getString(int combination) {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i <= 26; i++) {
            int index = (1 << i);
            if ((combination & index) != 0) {
                char appendChar = (char) ('A' + i);
                stringBuilder.append(appendChar);
            }
        }
        return stringBuilder.toString();
    }
}
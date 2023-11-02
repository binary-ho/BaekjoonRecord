import java.util.*;
import java.util.stream.*;
import java.io.*;


public class Main {
    // 모든 염기서열을 커버 가능한 최소 갯수
    // 그게 존재 하냐?
    // 최대 15개가 주어지기 때문에 최대 15개이다

    // 공존할 수 있는 쌍을 찾기?
    // 누구랑 공존할 지도 중요해
    // 그 모든 경우의 쌍을 구해도 2^15이 안 됨 적은 갯수다.
    // 모든 부분 집합을 살펴보자.
    // 15면 14 제곱?

    private static int N, M;
    private static int cnt = 0;
    private static List<String> DNAs;

    private static List<Integer> subsets = new ArrayList<>();
    private static Map<Integer, String> superDNAs = new HashMap<>();


    static int answer;
    // 이미 해본 조합을 또 하고 있는게 문제야.
    // 줄일만큼 줄임. 반대 수가 있으면 바로 끝내기?
    // 그래도 안 됨. 되는 조합을 저장하기?
    static Map<Integer, Integer> combinations = new HashMap<>();
    static void dfs(Integer set, int index, int cnt) {
        if (cnt >= answer) {
            return;
        }

        if (set == ((1 << N) - 1)) {
            answer = cnt;
            return;
        }

        int negative = (1 << N) - 1 - set;
        Integer combinationCnt = combinations.get(negative);
        if (combinationCnt != null) {
            dfs((1 << N) - 1, subsets.size(), cnt + combinationCnt);
        }

        for (int i = index + 1; i < subsets.size(); i++) {
            if (cnt + 1 >= answer) {
                return;
            }

            Integer subset = subsets.get(i);
            if ((set & subset) != 0) {
                continue;
            }

            Integer combination = set | subset;
            combinations.putIfAbsent(combination, cnt + 1);
            dfs(combination, i, cnt + 1);
        }
        return;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        N = Integer.parseInt(stringTokenizer.nextToken());
        answer = N;
        M = Integer.parseInt(stringTokenizer.nextToken());
    
        DNAs = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            String DNA = stringTokenizer.nextToken();
            DNAs.add(DNA);
            superDNAs.put((1 << i), DNA);
        }

        // 예를 들어 3개면 111
        // (1 << 3) - 1 부터 0까지
        // int max = (1 << N);
        for (int i = 0; i < (1 << N); i++) {
            // 돼 문자열, 안돼 ""
            List<Integer> subset = getSubset(i);
            // 되는지 판단해서 넣는다. 
            String superDNA = mergeDNA(subset);
            if (superDNA != "") {
                subsets.add(i);
            }
        }

        for (Integer subset : subsets) {
            combinations.put(subset, 1);
        }

        Collections.reverse(subsets);
        for (int i = 0; i < subsets.size(); i++) {
            dfs(subsets.get(i), i, 1);
        }
        System.out.println(answer);
    }

    private static List<Integer> getSubset(final int combination) {
        List<Integer> subset = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if ((combination & (1 << i)) == 0) {
                continue;
            }

            subset.add(i);
        }
        return subset;
    }

    // subset get은 DNA의 인덱스임을 명심
    private static String mergeDNA(List<Integer> DNAIndex) {
        if (DNAIndex.size() == 0) {
            return "";
        }

        // 15 * 3만 2천
        int mergeNumber = (1 << DNAIndex.get(0));
        StringBuilder superDNA = new StringBuilder(superDNAs.get(mergeNumber));

        for (int i = 1; i < DNAIndex.size(); i++) {
            mergeNumber |= (1 << DNAIndex.get(i));
            String discoveredDNA = superDNAs.get(mergeNumber);
            if (discoveredDNA != null) {
                if (discoveredDNA == "") {
                    return "";
                }

                superDNA = new StringBuilder(discoveredDNA);
                continue;
            }

            String DNA = DNAs.get(DNAIndex.get(i));
            for (int j = 0; j < M; j++) {
                if (superDNA.charAt(j) == DNA.charAt(j)) {
                    continue;
                }

                if (superDNA.charAt(j) != '.' && DNA.charAt(j) != '.') {
                    superDNAs.putIfAbsent(mergeNumber, "");
                    return "";
                }

                char newChar = superDNA.charAt(j);
                if (newChar == '.') {
                    newChar = DNA.charAt(j);
                }
                superDNA.replace(j, j + 1, String.valueOf(newChar));
            }
            superDNAs.putIfAbsent(mergeNumber, superDNA.toString());
        }

        superDNAs.putIfAbsent(mergeNumber, superDNA.toString());
        return superDNA.toString();
    }
}

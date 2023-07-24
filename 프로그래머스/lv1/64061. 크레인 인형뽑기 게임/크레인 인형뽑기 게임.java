import java.util.*;
import java.io.*;

public class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        List<Integer> doll = new LinkedList<>();
        for (int i = 0; i < moves.length; i++) {
            int move = moves[i] - 1;
            for (int j = 0; j < board.length; j++) {
                if (board[j][move] != 0) {
                    doll.add(board[j][move]);
                    board[j][move] = 0;
                    break;
                }
            }
            if (doll.size() < 2
               || doll.get(doll.size() - 2) != doll.get(doll.size() - 1)) continue;
            doll.remove(doll.size() - 1);
            doll.remove(doll.size() - 1);
            answer += 2;
        }
        return answer;
    }
}
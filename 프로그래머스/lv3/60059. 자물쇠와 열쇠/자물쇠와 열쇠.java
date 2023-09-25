import java.util.*;

class Solution {
    
    // 1 : 44
    // 4 * M^2 * (N - M + 1)^2 -> 최악 4 * 100 * 100
    // 아니다 4 * M^4이였음 -> 64만
    int[][] key;
    public boolean solution(int[][] keyInput, int[][] lock) {
        
        key = keyInput;
        int holeCount = 0;        
        for (int i = 0; i < lock.length; i++) {
            for (int j = 0; j < lock.length; j++) {
                if (lock[i][j] != 0) continue;
                holeCount++;
            }
        }
        
        int T = 4;
        while (T-- > 0) {
            // 시작점
            for (int i = -key.length; i < lock.length; i++) {
                for (int j = -key.length; j < lock.length; j++) {
                    boolean check = true;
                    int unlockCount = 0;
                    // 홀 좌표 - 시작점 => key에서의 좌표
                    // 돌기끼리 겹치면 안 돼
                    for (int r = 0; r < key.length; r++) {
                        for (int c = 0; c < key.length; c++) {
                            int lockY = i + r;
                            int lockX = j + c;
                            if (lockY < 0 || lockY >= lock.length
                               || lockX < 0 || lockX >= lock.length) continue;
                            
                            if (lock[lockY][lockX] == 0) {
                                if (key[r][c] == 1) {
                                    unlockCount++;
                                } else {
                                    check = false;
                                    break;
                                }
                            } else {
                                if (key[r][c] == 1) {
                                    check = false;
                                    break;
                                }
                            }
                        }
                        if (!check) break;
                    }
                    
                    if (check && unlockCount == holeCount) {
                        return true;
                    }
                }
            }
            
            spin();
        }
        
        return false;
    }
    
    void spin() {
        int length = key.length;
        int[][] newKey = new int[length][length];
        for (int r = 0; r < length; r++) {
            for (int c = 0; c < length; c++) {
                newKey[c][length - r - 1] = key[r][c];
            }
        }
        key = newKey;
    }
    
    class Axis {
        int y;
        int x;
        Axis(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
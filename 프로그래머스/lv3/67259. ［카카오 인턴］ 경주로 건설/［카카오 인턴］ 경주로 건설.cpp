#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N, dist[25][25],dist2[25][25];
int dy[4] = {0, 0, 1, -1};
int dy2[4] = {1, -1, 0, 0};
int dx[4] = {1, -1, 0, 0};
int dx2[4] = {0, 0, 1, -1};
vector<vector<int>> boardCopy;
void dfs(int y, int x, int arrow) {
    int newY, newX, cost;
    for(int i = 0; i < 4; i++) {
        newY = y + dy[i]; newX = x + dx[i];
        if(newY < 0 || newY >= N || newX < 0 || newX >= N || boardCopy[newY][newX] == 1) continue;
        if(arrow == 0) {
            cost = i < 2 ? 100 : 600;
        } else if(arrow == 1) {
            cost = i >= 2 ? 100 : 600;
        } else {
            cost = 100;
        }
        //if(check[newY][newX] && dist[newY][newX] <= dist[y][x] + cost) continue;
        if(dist[newY][newX] != -1 && dist[newY][newX] < dist[y][x] + cost) continue;
        if(dist[newY][newX] == -1 || dist[newY][newX] > dist[y][x] + cost) dist[newY][newX] = dist[y][x] + cost;
        dfs(newY, newX, i >> 1);
    }
}
void dfs2(int y, int x, int arrow) {
    int newY, newX, cost;
    for(int i = 0; i < 4; i++) {
        newY = y + dy2[i]; newX = x + dx2[i];
        if(newY < 0 || newY >= N || newX < 0 || newX >= N || boardCopy[newY][newX] == 1) continue;
        if(arrow == 0) {
            cost = i < 2 ? 100 : 600;
        } else if(arrow == 1) {
            cost = i >= 2 ? 100 : 600;
        } else {
            cost = 100;
        }
        //if(check[newY][newX] && dist[newY][newX] <= dist[y][x] + cost) continue;
        if(dist2[newY][newX] != -1 && dist2[newY][newX] < dist2[y][x] + cost) continue;
        if(dist2[newY][newX] == -1 || dist2[newY][newX] > dist2[y][x] + cost) dist2[newY][newX] = dist2[y][x] + cost;
        dfs2(newY, newX, i >> 1);
    }
}
// 오왼, 위아래, 자유
int solution(vector<vector<int>> board) {
    N = board.size();
    for(int i = 0; i < N; i++) {
        boardCopy.emplace_back(board[i]);
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dist[i][j] = dist2[i][j] = -1;
    dist[0][0] = dist2[0][0] = 0;
    dfs(0, 0, 2);
    dfs2(0, 0, 2);
    return min(dist[N-1][N-1], dist2[N-1][N-1]);
}
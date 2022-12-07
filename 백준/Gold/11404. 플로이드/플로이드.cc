#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int INF = 100000000;

int n, m, a, b, c;
int edge[101][101];
int dist[101][101];

int main() {
    cin >> n >> m;
    /* 모든 경로에 대해 INF 값을 대입 */
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) edge[i][j] = INF;

    /* 경로들을 입력으로 받는 부분
     * 이미 알고 있는 경로보다 더 짧은 경로라면 갱신해준다.
     * 초기에 모든 노드들간의 거리를 INF로 잡았으므로, 초기 입력은 무조건 받아들여진다. */
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (edge[a][b] > c) edge[a][b] = c;
    }

    /*
     * 플로이드 - 와샬 전처리 과정: 1회차 1번 노드를 거치는 경로 갱신
     * i에서 j로 가는 경로를 결정하는데,
     * i에서 j로 가는 원래 경로와, **i에서 j까지 1번 노드를 거쳐서 가는 경로** 중에서,
     * 더 짧은 거리를 경로로 택한다.
     * 같은 노드간의 이동은 불가능 하므로, 0을 대입해준다.
     * */
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) { 
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = min(edge[i][j], edge[i][1] + edge[1][j]);
        }
    }

    /*
     * 모든 노드 쌍에 대해 거리를 계산한다
     * k는 몇 회차 이완 행위인지를 나타낸다. 전처리 과정에서 1회의 갱신을 해주었으므로, 2 부터 진행한다.
     * */
    for (int k = 2; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int output = dist[i][j];
            if (output >= INF) output = 0;
            cout << output << ' ';
        }
        cout << '\n';
    }
}
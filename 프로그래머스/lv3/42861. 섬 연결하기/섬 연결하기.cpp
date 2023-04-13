#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> vec1, vector<int> vec2) {
    return vec1[2] < vec2[2];
}

struct disjointSet {
    
    vector<int> parent, rank;
    
    disjointSet(int N) {
        parent = vector<int>(N + 1);
        rank = vector<int>(N + 1, 1);
        
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }
    
    void unionNode(int u, int v) {
        u = parent[u];
        v = parent[v];
        
        if (u == v) {
            return;
        }
        
        if (rank[u] > rank[v]) {
            swap(u, v);
        }
        
        parent[u] = v;
        
        if (rank[u] == rank[v]) {
            rank[v]++;
        }
    }
};


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    
    disjointSet st(n);
    
    for (vector<int> vec : costs) {
        if (st.find(vec[0]) == st.find(vec[1])) {
            continue;
        }
        
        st.unionNode(vec[0], vec[1]);
        answer += vec[2];
    }
    
    return answer;
}
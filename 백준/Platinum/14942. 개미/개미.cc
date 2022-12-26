#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int N, energy[MAX], grave[MAX];
bool check[MAX];
vector<pair<int, int>> cave[MAX];

int idxToAnt[MAX];
vector<int> ant;
void caveConquer(int caveNow, int energyNow) {
    int findEnergy = energyNow - energy[caveNow];
    auto itr = lower_bound(ant.begin(), ant.end(), findEnergy);
//    cout << *itr << '\n';
    grave[caveNow] = idxToAnt[itr - ant.begin()];

    for (int i = 0; i < cave[caveNow].size(); i++) {
        auto nextCave = cave[caveNow][i];
        if (check[nextCave.first]) continue;
        check[nextCave.first] = true;
        idxToAnt[ant.size()] = nextCave.first;
        ant.emplace_back(energyNow + nextCave.second);
        caveConquer(nextCave.first, energyNow + nextCave.second);
        ant.pop_back();
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> energy[i];

    int a, b, c;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        cave[a].emplace_back(b, c);
        cave[b].emplace_back(a, c);
    }

    check[1] = true;
    idxToAnt[0] = 1;
    ant.emplace_back(0);
    caveConquer(1, 0);
    for (int i = 1; i <= N; i++) {
        cout << grave[i] << '\n';
    }
}

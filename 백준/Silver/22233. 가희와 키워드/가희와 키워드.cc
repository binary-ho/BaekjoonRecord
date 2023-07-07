#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    string keyword, buffer;
    set<string> st;
    for (int i = 0; i < N; i++) {
        cin >> keyword;
        st.insert(keyword);
    }

    stringstream ss;
    for (int i = 0; i < M; i++) {
        cin >> buffer;
        ss.clear();
        ss.str(buffer);
        while (getline(ss, buffer, ',')) {
            if (st.find(buffer) == st.end()) continue;
            st.erase(buffer);
        }
        cout << st.size() << '\n';
    }
}

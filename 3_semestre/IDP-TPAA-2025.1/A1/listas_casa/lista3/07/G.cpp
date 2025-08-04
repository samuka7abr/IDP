#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    unordered_map<int, pair<int, int>> pos;
    pos.reserve(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            if (pos.find(x) == pos.end()) {
                pos[x] = {i, j};  
            }
        }
    }
    
    while (Q--) {
        int v;
        cin >> v;
        if (pos.find(v) != pos.end()) {
            cout << pos[v].first << " " << pos[v].second << "\n";
        } else {
            cout << "-1 -1" << "\n";
        }
    }
    
    return 0;
}

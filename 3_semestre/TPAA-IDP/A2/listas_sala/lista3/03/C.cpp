#include <bits/stdc++.h>
using namespace std;

int N, M, C;
vector<vector<int>> adj;
vector<bool> camera, visitado;
vector<int> dist;

void bfs(int origem, bool evita) {
    for (int i = 1; i <= N; ++i) {
        visitado[i] = false;
        dist[i] = -1;
    }
    queue<int> q;
    if (evita && camera[origem]){
        return;
    }
    visitado[origem] = true;
    dist[origem] = 0;
    q.push(origem);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visitado[v] && !(evita && camera[v])) {
                visitado[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> C;
    camera.assign(N + 1, false);
    for (int i = 0; i < C; i++) {
        int p; 
        cin >> p;
        camera[p] = true;
    }
    
    adj.assign(N+1, {});
    for (int i = 0; i < M; i++) {
        int A, B; 
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    int E, S, K;
    cin >> E >> S >> K;
    
    visitado.assign(N + 1, false);
    dist.assign(N + 1, -1);

    bfs(E, true);
    int d1 = dist[K];
    
    bfs(E, false);
    int d2 = dist[S];
    
    if (d1 == -1 || d2 == -1) {
        cout << "impossivel fugir" << endl;
    } else {
        cout << (d1 * 2) << " " << d2 << endl;
    }

    return 0;
}

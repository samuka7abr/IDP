#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector<vector<int>> adj;
vector<bool> visitado;
vector<int> dist;

void bfs(int origem){
    for(int i = 1; i <= N; i++){
        visitado[i] = false;
        dist[i] = -1;
    }
    queue<int> q;
    visitado[origem] = true;
    dist[origem] = 0;
    q.push(origem);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visitado[v]) {
                visitado[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    adj.assign(N + 1, {});
    visitado.assign(N + 1, false);
    dist.assign(N + 1, -1);


    while(M--){
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int origem, extintor, foco;
    cin >> origem >> extintor >> foco;

    bfs(origem);
    int d1 = dist[extintor];

    bfs(extintor);
    int d2 = dist[foco];

    int resultado = d1 + d2;

    cout << resultado << endl;

    return 0;
}

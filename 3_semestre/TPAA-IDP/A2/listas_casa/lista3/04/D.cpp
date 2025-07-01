#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int M, N;
vector<vector<int>> adj;
vector<bool> visitado;
vector<int> dist;

void bfs(int origem) {
    for(int i = 1; i <= M; i++){
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
    cin >> M >> N;

    adj.assign(M+1, {});
    visitado.assign(M+1, false);
    dist.assign(M+1, -1);

    while(N--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    if(dist[M] != -1){
        cout << dist[M] << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}

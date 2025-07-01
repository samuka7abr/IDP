#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18; 

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;

void bfs(int origem){
    for(int i = 1; i <= N; i++){
        visited[i] = false;
        dist[i] = -1;
    }

    queue<int> q;
    visited[origem] = true;
    dist[origem] = 0;
    q.push(origem);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    otim;
    cin >> N >> M;

    adj.assign(N + 1, {});
    visited.assign(N + 1, false);
    dist.assign(N + 1, -1);

    while(M--){
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
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

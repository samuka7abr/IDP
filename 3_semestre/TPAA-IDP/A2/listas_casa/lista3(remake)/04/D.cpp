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

int M, N;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;

void bfs(int origem){
    for(int i = 1; i <= M; i++){
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
    cin >> M >> N;

    adj.assign(M+1, {});
    visited.assign(M+1, false);
    dist.assign(M+1, -1);

    while(N--){
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfs(1);
    
    if(dist[M] != -1){
        cout << dist[M] << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}

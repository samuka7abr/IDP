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

void dfs(int u, int &count){ 
    visited[u] = true;
    count++;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v, count);
        }
    }
}

int main(){
    otim;
    cin >> N >> M;

    ll completo = 1LL * N * (N - 1) / 2;
 
    if(M == completo){
        cout << "O grupo mais numeroso tem " << N << " aluno(s)\n";
        return 0;
    }

    adj.assign(N + 1, {});
    visited.assign(N + 1, false);

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    int melhor = 1;
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            int count = 0;
            dfs(i, count);
            melhor = max(melhor, count);
        }
    }

    cout << "O grupo mais numeroso tem " << melhor << " aluno(s)" << endl;

    return 0;
}

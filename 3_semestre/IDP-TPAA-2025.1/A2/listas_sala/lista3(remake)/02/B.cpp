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

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main(){
    otim;
    cin >> N >> M;

    adj.assign(N + 1, vector<int>());
    visited.assign(N + 1, false);

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    int gangs = 0;

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            dfs(i);
            gangs ++;
        }
    }

    cout << gangs << " gangue(s) no clube da briga" << endl;

    return 0;
}

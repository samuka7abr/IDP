#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int u, const vector<vector<int>> &adj, vector<bool> &visitado, int &count){
    visitado[u] = true;
    count++;
    for(int v : adj[u]){
        if(!visitado[v]){
            dfs(v, adj, visitado, count);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visitado(N + 1, false);

    int count = 0;
    dfs(1, adj, visitado, count);

    if(count == N){
        cout << "Todo mundo eh amigo de todo mundo" << endl;
    }else{
        cout << "Varios grupos de amigos" << endl;
    }

    return 0;
}

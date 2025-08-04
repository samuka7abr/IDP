#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int M, N;
vector<vector<int>> adj;
vector<bool>visitado;

void dfs(int u, int &cnt){
    visitado[u] = true;
    cnt++;

    for(int v: adj[u]){
        if(!visitado[v]){
            dfs(v, cnt);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    ll completo = 1LL * N * (N - 1) / 2;

    if(M == completo){
        cout << "O grupo mais numeroso tem " << N << " aluno(s)\n";
        return 0;
    }

    adj.assign(M + 1, {});
    visitado.assign(M + 1, false);

    for(int i = 0; i < N; i++){
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    int melhor = 1;
    
    for(int u = 1; u <= M; u++){
        if(!visitado[u]){
            int cnt = 0;
            dfs(u, cnt);
            melhor = max(melhor, cnt);
        }
    }
    
    cout << "O grupo mais numeroso tem " << melhor << " aluno(s)" << endl;



    return 0;
}

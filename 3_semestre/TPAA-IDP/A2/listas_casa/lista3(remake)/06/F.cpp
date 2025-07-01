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
vector<vector<pii>>adj;
vector<int> dist;

void dijkstra(int origem){
    fill(dist.begin(), dist.end(), INF_INT);
    
    dist[origem] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, origem});

    while(!pq.empty()){
        auto [d,  u] = pq.top(); 
        pq.pop();
        if(d > dist[u]){
            continue;
        }
        for(auto [v, w] : adj[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    otim;
    cin >> N >> M;

    adj.assign(N + 1, {});
    dist.assign(N + 1, INF_INT);

    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijkstra(1);

    if(dist[N] == INF_INT){
        cout << "Preso no IDP" << endl;
    }else{
        cout << "Distancia para chegar em casa: " << dist[N] << endl;
    }

    return 0;
}

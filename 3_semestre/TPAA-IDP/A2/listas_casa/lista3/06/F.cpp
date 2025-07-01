#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int N, M;
vector<vector<pair<int, int>>> adj;
vector<bool> visitado;
vector<int> dist;

void dijkstra(int origem)
{
    fill(dist.begin(), dist.end(), INF);

    dist[origem] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, origem});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto [v, w]: adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
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
    dist.assign(N + 1, INF);

    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    if(dist[N] == INF){
        cout << "Preso no IDP" << endl;
    }else{
        cout << "Distancia para chegar em casa: " << dist[N] << endl;
    }

    return 0;
}

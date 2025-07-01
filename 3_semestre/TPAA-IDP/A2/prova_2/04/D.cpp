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
vector<vector<pii>> adj;

vector<ll> dijkstra(int origem, int n) {
    vector<ll> dist(n + 1, INF_LL);

    priority_queue<pair<ll,int>> pq;

    dist[origem] = 0;
    pq.push({0, origem});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        d = -d;

        if (d > dist[u]){
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({-dist[v], v});
            }
        }
    }

    return dist;
}

int main(){
    otim;
    cin >> N >> M;
    adj.assign(N +1, {});
    for (int i = 0; i < M; i++){
        int U, V, W;
        cin >> U >> V >> W;
        adj[U].pb({V, W});
    }
    auto dist1 = dijkstra(1, N);
    auto distN = dijkstra(N, N);

    if (dist1[N] == INF_LL || distN[1] == INF_LL) {
        cout << "impossivel saltar\n";
    } else {
        cout << "distancia minima eh de " << (dist1[N] + distN[1]) << endl;
    }

    return 0;
}

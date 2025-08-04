#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int N, M;
vector<vector<pair<int,int>>> adj;
vector<int> dist;

void dijkstra(int origem) {
    for (int i = 1; i <= N; ++i) {
        dist[i] = INF;
    }
    dist[origem] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, origem});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &beira : adj[u]) {
            int v = beira.first;
            int w = beira.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    adj.assign(N + 1, {});
    dist.assign(N + 1, INF);

    for (int i = 0; i < M; ++i) {
        int U, V, W;
        cin >> U >> V >> W;
        adj[U].push_back({V, W});
        adj[V].push_back({U, W});
    }

    dijkstra(1);

    int maxDis = 0;
    for (int i = 2; i <= N; ++i) {
        if (dist[i] == INF) {
            cout << "Impossivel chegar" << endl;
            return 0;
        }
        maxDis = max(maxDis, dist[i]);
    }

    cout << "Casa mais distante a " << maxDis << " metros" << endl;
    return 0;
}

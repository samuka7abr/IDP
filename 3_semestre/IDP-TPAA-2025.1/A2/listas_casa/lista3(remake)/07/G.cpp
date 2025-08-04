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

struct Aresta {
    int origem, destino, peso;
};
 
int m, n;
vector<Aresta> arestas;
vector<int> pai, ranque;
 
int find_set(int x) {
    if (pai[x] != x)
        pai[x] = find_set(pai[x]);
    return pai[x];
}
 
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (ranque[a] < ranque[b]) {
        pai[a] = b;
    } else if (ranque[b] < ranque[a]) {
        pai[b] = a;
    } else {
        pai[b] = a;
        ranque[a]++;
    }
}
 
int main() {
    otim;
 
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> n;
        arestas.assign(n, {0, 0, 0});
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arestas[i].origem = x;
            arestas[i].destino = y;
            arestas[i].peso = z;
        }
 
        sort(arestas.begin(), arestas.end(), [](const Aresta &a, const Aresta &b) {
            return a.peso < b.peso;
        });
 
        pai.assign(m + 1, 0);
        ranque.assign(m + 1, 0);
        for (int i = 1; i <= m; i++) {
            pai[i] = i;
            ranque[i] = 0;
        }
 
        ll total = 0;
        int escolhidas = 0;
        for (int i = 0; i < n; i++) {
            int u = arestas[i].origem;
            int v = arestas[i].destino;
            int w = arestas[i].peso;
            if (find_set(u) != find_set(v)) {
                total += w;
                union_set(u, v);
                escolhidas++;
                if (escolhidas == m - 1) break;
            }
        }
 
        cout << total << "\n";
    }
 
    return 0;
}

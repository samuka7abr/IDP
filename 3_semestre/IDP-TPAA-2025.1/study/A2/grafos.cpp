#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// --------------------------------------------------
// Implementações usando Lista de Adjacência
// --------------------------------------------------
 
int N;  
vector<vector<int>> adj;    // adj[u] = lista de vizinhos de u
vector<bool> visited;       // visited[u] indica se u já foi visitado

// DFS recursivo em Lista de Adjacência
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// DFS iterativo em Lista de Adjacência
void dfs_iter(int start) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                st.push(v);
            }
        }
    }
}

// BFS em Lista de Adjacência
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// --------------------------------------------------
// Implementações usando Matriz de Adjacência
// --------------------------------------------------

int N2;  
vector<vector<int>> mat;    // mat[u][v] = 1 se há aresta u→v, 0 caso contrário
vector<bool> visited_mat;   // visited_mat[u] para busca em matriz

// Inicializa uma matriz de adjacência de tamanho n × n com zeros
void init_matrix(int n) {
    N2 = n;
    mat.assign(n, vector<int>(n, 0));
    visited_mat.assign(n, false);
}

// Adiciona aresta não-direcionada (u ↔ v)
void add_edge_undirected(int u, int v) {
    mat[u][v] = 1;
    mat[v][u] = 1;
}

// Adiciona aresta direcionada (u → v)
void add_edge_directed(int u, int v) {
    mat[u][v] = 1;
}

// DFS recursivo em Matriz de Adjacência
void dfs_mat(int u) {
    visited_mat[u] = true;
    for (int v = 0; v < N2; v++) {
        if (mat[u][v] && !visited_mat[v]) {
            dfs_mat(v);
        }
    }
}

// BFS em Matriz de Adjacência
void bfs_mat(int start) {
    queue<int> q;
    visited_mat[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < N2; v++) {
            if (mat[u][v] && !visited_mat[v]) {
                visited_mat[v] = true;
                q.push(v);
            }
        }
    }
}

// --------------------------------------------------
// Implementações para Grafo Ponderado (Dijkstra)
// --------------------------------------------------

int Nw;    // número de vértices no grafo ponderado
// adjw[u] = lista de pares (v, w) representando aresta u→v com peso w
vector<vector<pair<int,int>>> adjw;
vector<ll> distw;  // distw[u] = distância mínima da fonte até u

// Inicializa grafo ponderado de n vértices
void init_weighted_graph(int n) {
    Nw = n;
    adjw.assign(n, {});
    distw.assign(n, LLONG_MAX);
}

// Adiciona aresta não-direcionada com peso w (u ↔ v)
void add_edge_w_undirected(int u, int v, int w) {
    adjw[u].push_back({v, w});
    adjw[v].push_back({u, w});
}

// Adiciona aresta direcionada com peso w (u → v)
void add_edge_w_directed(int u, int v, int w) {
    adjw[u].push_back({v, w});
}

// Dijkstra a partir da fonte s (0-based)
void dijkstra(int s) {
    // Inicialização
    distw.assign(Nw, LLONG_MAX);
    distw[s] = 0;
    // Min-heap de pares (dist, vértice)
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        // Se d for maior que a melhor distância registrada, ignora
        if (d > distw[u]) continue;
        // Relaxa arestas de u
        for (auto &[v, w] : adjw[u]) {
            if (distw[v] > d + w) {
                distw[v] = d + w;
                pq.push({distw[v], v});
            }
        }
    }
}

int main() {
    // Este espaço pode ser usado para inicializar e testar as funções acima.

    return 0;
}

typedef struct vertice {
    int id; 
    struct vertice* prox; 
} Vertice;

typedef struct listaArestas {
    Vertice* head;
} ListaArestas;

//struct para o grafo
typedef struct grafo {
    int nro_vertices; 
    ListaArestas* arestas;
} Grafo;

Grafo* cria_grafo(int nro_vertices);
void adiciona_aresta(Grafo* gr, int origem, int destino);
void exibe_grafo(Grafo* gr);
void libera_grafo(Grafo* gr);

//BUSCA
void dfs(Grafo* gr, int origem, int* visitados, int* resultado, int* index, int* cds, int n_cds, int* pais);
int bfs(Grafo* gr, int origem, int* cds, int n_cds, int* pais);
void exibir_caminho(int* pais, int origem, int destino, const char** capitais);

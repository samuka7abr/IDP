struct aluno {
    int matricula;
    char nome[50];
    float ap1, ap2, ap3, ap4, np, av;
};

struct elemento {
    struct aluno dados;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;
typedef Elem* Lista;

// Protótipos
Lista* cria_lista();
void libera_lista(Lista* li);
int lista_vazia(Lista* li);
float calcular_nota(float ap1, float ap2, float ap3, float ap4, float np);
int insere_lista_ordenada(Lista* li, struct aluno al);
void imprime_lista(Lista* li);
Lista* concatena_listas(Lista* lista1, Lista* lista2);
void inverte_lista(Lista* li);

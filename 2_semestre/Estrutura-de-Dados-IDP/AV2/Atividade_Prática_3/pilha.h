typedef struct elemento {
    int dado;
    struct elemento* prox;
} Elemento;

typedef Elemento* Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha* pi);
int empilha(Pilha* pi, int valor);
int desempilha(Pilha* pi, int* valor);
int pilha_vazia(Pilha* pi);
void converte_base(int numero, int base);



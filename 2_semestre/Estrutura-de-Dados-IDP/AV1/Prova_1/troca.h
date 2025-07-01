#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int valor;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

int troca(Lista *li, int n);
Lista* cria_lista();
void imprime_lista(Lista* li);
int insere_lista_final(Lista* li, int valor);






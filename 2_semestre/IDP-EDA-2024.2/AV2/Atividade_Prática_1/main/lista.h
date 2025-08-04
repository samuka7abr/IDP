#ifndef LISTA_H
#define LISTA_H

#include "tipos.h"  // Inclui a definição de Paciente

typedef struct lista_elemento {
    Paciente dados;
    struct lista_elemento *prox;
} ListaElem;

typedef struct lista {
    ListaElem *inicio;
} Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista(Lista* li, Paciente p);
int remove_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);

#endif // LISTA_H

#ifndef FILA_H
#define FILA_H

#include "tipos.h"  // Inclui a definição de Paciente

typedef struct elemento {
    Paciente dados;
    struct elemento *prox;
} Elem;

typedef struct fila {
    Elem *inicio;
    Elem *final;
    int qtd;
} Fila;

Fila* cria_fila();
void libera_fila(Fila* f);
int insere_fila(Fila* f, Paciente p);
int remove_fila(Fila* f);
int tamanho_fila(Fila* f);
int fila_vazia(Fila* f);

#endif // FILA_H

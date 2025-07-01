// fila.c
// gcc -shared -o libfila.so -fPIC fila.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int dado;
    struct Elemento* prox;
} Elemento;

typedef struct Fila {
    Elemento* inicio;
    Elemento* final;
} Fila;

Fila* criaFila() {
    Fila* q = (Fila*)malloc(sizeof(Fila));
    q->inicio = q->final = NULL;
    return q;
}

void enfileira(Fila* q, int valor) {
    Elemento* no = (Elemento*)malloc(sizeof(Elemento));
    no->dado = valor;
    no->prox = NULL;
    if (q->final == NULL) {
        q->inicio = q->final = no;
        return;
    }
    q->final->prox = no;
    q->final = no;
}

int desenfileira(Fila* q) {
    if (q->inicio == NULL) {
        return 0; // Queue is empty
    }
    Elemento* no = q->inicio;
    int valor = no->dado;
    q->inicio = q->inicio->prox;
    if (q->inicio == NULL) {
        q->final = NULL;
    }
    free(no);
    return valor;
}

void imprimeFila(Fila* q) {
    Elemento* no = q->inicio;
    while (no != NULL) {
        printf("%d ", no->dado);
        no = no->prox;
    }
    printf("\n");
}

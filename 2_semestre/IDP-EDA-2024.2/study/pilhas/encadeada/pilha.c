#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Inicializa a pilha com o topo nulo e tamanho zero
void inicializa_pilha(Pilha* p) {
    p->topo = NULL;
    p->tamanho = 0;
}

// Insere um elemento no topo da pilha
int push(Pilha* p, int valor) {
    if (isFull(p)) return 0;

    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
    return 1;
}

// Remove o elemento do topo da pilha
int pop(Pilha* p, int* valor) {
    if (isEmpty(p)) return 0;

    No* temp = p->topo;
    *valor = temp->valor;
    p->topo = temp->prox;
    free(temp);
    p->tamanho--;
    return 1;
}

// Consulta o elemento no topo sem removê-lo
int peek(Pilha* p, int* valor) {
    if (isEmpty(p)) return 0;
    *valor = p->topo->valor;
    return 1;
}

// Verifica se a pilha está vazia
int isEmpty(Pilha* p) {
    return (p->topo == NULL);
}

// Verifica se a pilha está cheia
int isFull(Pilha* p) {
    return (p->tamanho == TAMANHO);
}

// Exibe todos os elementos da pilha
void exibir(Pilha* p) {
    if (isEmpty(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    No* atual = p->topo;
    printf("Elementos da pilha: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

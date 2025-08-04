#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

//PILHA
Pilha* cria_pilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void adiciona_pilha(Pilha* p, Orgao* o) {
    o->prox = p->topo;
    p->topo = o;
}

Orgao* remove_pilha(Pilha* p) {
    if (p->topo == NULL) return NULL;
    Orgao* removido = p->topo;
    p->topo = p->topo->prox;
    removido->prox = NULL;
    return removido;
}

void exibe_pilha(Pilha* p) {
    printf("Pilha de Alta Prioridade:\n");
    Orgao* atual = p->topo;
    while (atual) {
        printf("ID: %d, Tipo: %s, Origem: %s, Status: %s\n",
               atual->id, atual->tipo, atual->origem, atual->status);
        atual = atual->prox;
    }
}

void libera_pilha(Pilha* p) {
    Orgao* atual = p->topo;
    while (atual) {
        Orgao* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(p);
}

//FILA
Fila* cria_fila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void adiciona_fila(Fila* f, Orgao* o) {
    Orgao* atual = f->inicio;
    Orgao* anterior = NULL;

    if (f->inicio == NULL) {
        f->inicio = o;
        f->fim = o;
        o->prox = NULL;
        return;
    }

    while (atual != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = o;
    f->fim = o;
    o->prox = NULL;
}


Orgao* remove_fila(Fila* f) {
    if (f->inicio == NULL) return NULL;
    Orgao* removido = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    removido->prox = NULL;
    return removido;
}

void exibe_fila(Fila* f) {
    printf("Fila de Baixa Prioridade:\n");
    Orgao* atual = f->inicio;
    while (atual) {
        printf("ID: %d, Tipo: %s, Origem: %s, Status: %s\n",
               atual->id, atual->tipo, atual->origem, atual->status);
        atual = atual->prox;
    }
}

void libera_fila(Fila* f) {
    Orgao* atual = f->inicio;
    while (atual) {
        Orgao* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(f);
}

ListaGlobal* cria_lista_global() {
    ListaGlobal* lista = (ListaGlobal*) malloc(sizeof(ListaGlobal));
    lista->head = NULL;
    return lista;
}

void adiciona_lista_global(ListaGlobal* lista, Orgao* o) {
    o->prox = lista->head;
    lista->head = o;
}

void atualiza_status_lista_global(ListaGlobal* lista, int id, const char* novo_status) {
    Orgao* atual = lista->head;
    while (atual) {
        if (atual->id == id) {
            strcpy(atual->status, novo_status);
            return;
        }
        atual = atual->prox;
    }
    printf("Órgão com ID %d não encontrado na lista global.\n", id);
}

void exibe_lista_global(ListaGlobal* lista) {
    printf("Lista Global de Órgãos:\n");
    Orgao* atual = lista->head;
    while (atual) {
        printf("ID: %d, Tipo: %s, Origem: %s, Status: %s\n",
               atual->id, atual->tipo, atual->origem, atual->status);
        atual = atual->prox;
    }
}

void libera_lista_global(ListaGlobal* lista) {
    Orgao* atual = lista->head;
    while (atual) {
        Orgao* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}

bool pilha_vazia(Pilha* p) {
    return (p->topo == NULL);
}

bool fila_vazia(Fila* f) {
    return (f->inicio == NULL);
}
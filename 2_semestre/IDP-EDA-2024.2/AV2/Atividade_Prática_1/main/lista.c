#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        li->inicio = NULL;
    return li;
}

void libera_lista(Lista* li) {
    if (li != NULL) {
        ListaElem* no;  // Corrigido para ListaElem
        while (li->inicio != NULL) {
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista(Lista* li, Paciente p) {
    if (li == NULL) return 0;
    ListaElem* no = (ListaElem*) malloc(sizeof(ListaElem));  // Corrigido para ListaElem
    if (no == NULL) return 0;
    no->dados = p;
    no->prox = NULL;
    if (li->inicio == NULL) {
        li->inicio = no;
    } else {
        ListaElem* aux = li->inicio;  // Corrigido para ListaElem
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int remove_lista(Lista* li) {
    if (li == NULL || li->inicio == NULL) return 0;
    ListaElem* no = li->inicio;  // Corrigido para ListaElem
    li->inicio = li->inicio->prox;
    free(no);
    return 1;
}

int lista_vazia(Lista* li) {
    return (li == NULL || li->inicio == NULL);
}

int tamanho_lista(Lista* li) {
    int cont = 0;
    ListaElem* no = li->inicio;  // Corrigido para ListaElem
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDup.h"

Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;
        while (*li != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int lista_vazia(Lista* li) {
    return (li == NULL || *li == NULL);
}

float calcular_nota(float ap1, float ap2, float ap3, float ap4, float np) {
    float media_parcial = (ap1 + ap2 + ap3 + ap4) / 4;
    return (media_parcial * 0.4) + (np * 0.6);
}

int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    al.av = calcular_nota(al.ap1, al.ap2, al.ap3, al.ap4, al.np);
    no->dados = al;
    no->prox = NULL;
    no->ant = NULL;

    if (*li == NULL) {
        *li = no;
    } else {
        Elem* atual = *li;
        Elem* anterior = NULL;

        while (atual != NULL && atual->dados.av > al.av) {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL) {
            no->prox = *li;
            (*li)->ant = no;
            *li = no;
        } else {
            no->prox = atual;
            no->ant = anterior;
            anterior->prox = no;
            if (atual != NULL) {
                atual->ant = no;
            }
        }
    }
    return 1;
}

void imprime_lista(Lista* li) {
    if (lista_vazia(li)) {
        printf("Lista vazia.\n");
        return;
    }

    Elem* no = *li;
    while (no != NULL) {
        printf("Matrícula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Nota Final (AV): %.2f\n", no->dados.av);
        printf("-------------------------\n");
        no = no->prox;
    }
}

Lista* concatena_listas(Lista* lista1, Lista* lista2) {
    if (lista_vazia(lista1)) return lista2;
    if (lista_vazia(lista2)) return lista1;

    Elem* atual = *lista2;
    while (atual != NULL) {
        insere_lista_ordenada(lista1, atual->dados);
        atual = atual->prox;
    }
    return lista1;
}

void inverte_lista(Lista* li) {
    if (li == NULL || *li == NULL) return;

    Elem* atual = *li;
    Elem* temp = NULL;

    while (atual != NULL) {
        temp = atual->ant;
        atual->ant = atual->prox;
        atual->prox = temp;
        atual = atual->ant;
    }

    if (temp != NULL) {
        *li = temp->ant;
    }
}

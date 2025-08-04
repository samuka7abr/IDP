#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncadeada.h"

//funções base

Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li) {
    if (li != NULL) {
        struct elemento* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int lista_vazia(Lista* li) {
    if (li == NULL || *li == NULL)
        return 1;
    return 0;
}

int tamanho_lista(Lista* li) {
    if (li == NULL) return 0;
    int cont = 0;
    struct elemento* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

void imprime_lista(Lista* li) {
    if (li == NULL)
        return;
    Elem* no = *li;
    while (no != NULL) {
        float nota_final = calcular_nota(no->dados.n1, no->dados.n2, no->dados.n3, no->dados.n4, no->dados.np);

        printf("Codigo: %d\n", no->dados.codigo);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %.2f, %.2f, %.2f, %.2f\n", 
               no->dados.n1, 
               no->dados.n2, 
               no->dados.n3, 
               no->dados.n4);  
        printf("Nota Prova: %.2f\n", no->dados.np);
        printf("Nota Final: %.2f\n", nota_final);
        printf("-------------------------\n");

        no = no->prox;  
    }
}

float calcular_nota(float n1, float n2, float n3, float n4, float np) {
    float media_parcial = (n1 + n2 + n3 + n4) / 4;
    return (media_parcial * 0.4) + (np * 0.6);
}

int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL) {
        return 0;
    }
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

//funções das questões

int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL) { return 0; }
    struct elemento* no = (struct elemento*) malloc(sizeof(struct elemento));
    if (no == NULL) { return 0; }
    no->dados = al;
    if ((*li) == NULL || (*li)->dados.codigo > al.codigo) {
        no->prox = (*li);
        *li = no;
        return 1;
    } else {
        struct elemento* ant = *li;
        struct elemento* atual = (*li)->prox;
        while (atual != NULL && atual->dados.codigo < al.codigo) {
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = no;
        no->prox = atual;
        return 1;
    }
}

int remove_lista_inicio(Lista* li) {
    if (li == NULL) { return 0; }
    struct elemento* no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL || *li == NULL) return 0;
    struct elemento* ant = NULL;
    struct elemento* no = *li;
    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }
    if (ant == NULL) {
        *li = NULL;
    } else {
        ant->prox = NULL;
    }
    free(no);
    return 1;
}

int remove_lista_pelo_codigo(Lista* li, int cod) {
    if (li == NULL) return 0;
    struct elemento* ant = NULL;
    struct elemento* no = *li;
    while (no != NULL && no->dados.codigo != cod) {
        ant = no;
        no = no->prox;
    }
    if (no == NULL) return 0;
    if (ant == NULL) {
        *li = no->prox;
    } else {
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int consulta_lista_cod(Lista* li, int cod) {
    if (li == NULL) return 0;
    struct elemento* no = *li;
    while (no != NULL) {
        if (no->dados.codigo == cod) {
            printf("Aluno encontrado: %s (Código: %d)\n", no->dados.nome, no->dados.codigo);
            return 1;
        }
        no = no->prox;
    }
    return 0;
}

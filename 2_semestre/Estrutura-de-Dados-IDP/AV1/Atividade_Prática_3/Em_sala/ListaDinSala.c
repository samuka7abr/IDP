#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinSala.h"

// Funções base
Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;
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
    Elem* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

float calcular_nota(float ap1, float ap2, float ap3, float ap4, float np) {
    float media_parcial = (ap1 + ap2 + ap3 + ap4) / 4;
    return (media_parcial * 0.4) + (np * 0.6);
}

// Função para inserir no início
int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    al.av = calcular_nota(al.ap1, al.ap2, al.ap3, al.ap4, al.np);
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

void imprime_lista(Lista* li) {
    if (li == NULL) return;

    Elem* no = *li;
    while (no != NULL) {
        printf("Matrícula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %.2f, %.2f, %.2f, %.2f\n", no->dados.ap1, no->dados.ap2, no->dados.ap3, no->dados.ap4);
        printf("Nota Prova: %.2f\n", no->dados.np);
        printf("Nota Final (AV): %.2f\n", no->dados.av);  
        printf("-------------------------\n");
        no = no->prox;
    }
}

// Funções das questões
int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    al.av = calcular_nota(al.ap1, al.ap2, al.ap3, al.ap4, al.np);
    no->dados = al;

    if ((*li) == NULL || (*li)->dados.av < al.av) {  
        no->prox = (*li);
        *li = no;
        return 1;
    }

    Elem* ant = *li;
    Elem* atual = (*li)->prox;

    while (atual != NULL && atual->dados.av > al.av) {
        ant = atual;
        atual = atual->prox;
    }

    no->prox = atual;
    ant->prox = no;
    return 1;
}

int remove_lista_inicio(Lista* li) {
    if (li == NULL || *li == NULL) return 0;

    Elem* no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL || *li == NULL) return 0;

    Elem* ant = NULL;
    Elem* no = *li;

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

    Elem* ant = NULL;
    Elem* no = *li;

    while (no != NULL && no->dados.matricula != cod) {
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

    Elem* no = *li;
    while (no != NULL) {
        if (no->dados.matricula == cod) {
            printf("Aluno encontrado: %s (Matrícula: %d)\n", no->dados.nome, no->dados.matricula);
            return 1;
        }
        no = no->prox;
    }
    return 0;
}
int insere_melhores(Lista* li, struct aluno al) {
    if (li == NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    al.av = calcular_nota(al.ap1, al.ap2, al.ap3, al.ap4, al.np);
    no->dados = al;

    if ((*li) == NULL || (*li)->dados.av < al.av) {
        no->prox = (*li);
        *li = no;
    } else {
        Elem* ant = *li;
        Elem* atual = (*li)->prox;

        while (atual != NULL && atual->dados.av > al.av) {
            ant = atual;
            atual = atual->prox;
        }

        no->prox = atual;
        ant->prox = no;
    }

    if (tamanho_lista(li) > 10) {  
        remove_lista_final(li);
    }

    return 1;
}
int insere_piores(Lista* li, struct aluno al) {
    if (li == NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    al.av = calcular_nota(al.ap1, al.ap2, al.ap3, al.ap4, al.np);
    no->dados = al;

    if ((*li) == NULL || (*li)->dados.av > al.av) {
        no->prox = (*li);
        *li = no;
    } else {
        Elem* ant = *li;
        Elem* atual = (*li)->prox;

        while (atual != NULL && atual->dados.av < al.av) {
            ant = atual;
            atual = atual->prox;
        }

        no->prox = atual;
        ant->prox = no;
    }

    if (tamanho_lista(li) > 10) {  
        remove_lista_final(li);
    }

    return 1;
}


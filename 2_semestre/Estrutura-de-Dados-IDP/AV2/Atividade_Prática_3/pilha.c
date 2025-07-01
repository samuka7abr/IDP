#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;   
}
void libera_pilha(Pilha *pi){
    if(pi != NULL){
        Elemento* no;
        while(*pi != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}
int empilha(Pilha* pi, int valor){
    if(pi == NULL){return 0;}
    Elemento* no = (Elemento*)malloc(sizeof(Elemento));
    if(no == NULL){return 0;}
    no->dado = valor;
    no->prox = *pi;
    *pi = no;
    return 1;
}
int desempilha(Pilha* pi, int* valor) {
    if (pi == NULL || *pi == NULL) return 0;
    Elemento* no = *pi;
    *valor = no->dado;
    *pi = no->prox;
    free(no);
    return 1;
}
int pilha_vazia(Pilha* pi) {
    return (pi == NULL || *pi == NULL);
}

void converte_base(int numero, int base) {
    Pilha* pi = cria_pilha();
    int resto;

    while (numero > 0) {
        resto = numero % base;
        empilha(pi, resto);
        numero /= base;
    }
    printf("Resultado na base %d: ", base);
    while (!pilha_vazia(pi)) {
        desempilha(pi, &resto);
        if (base == 16 && resto >= 10) {
            printf("%c", 'A' + (resto - 10));
        } else {
            printf("%d", resto);
        }
    }
    printf("\n");
    libera_pilha(pi);
}

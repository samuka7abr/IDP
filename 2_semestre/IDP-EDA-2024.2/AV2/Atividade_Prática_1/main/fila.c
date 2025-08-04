#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila* cria_fila() {  // Corrigido o nome para "cria_fila"
    Fila* f = (Fila*) malloc(sizeof(Fila)); //cria um ponteiro tipo fila e aloca memória para ela
    if(f != NULL){
        f->inicio = NULL; // define o início e o fim como NULL, pois a fila está vazia
        f->final = NULL;
    }
    return f;
}

void libera_fila(Fila* f) {
    if(f != NULL) {
        Elem* no; // ponteiro para percorrer a fila e liberar cada elemento
        while(f->inicio != NULL) {
            no = f->inicio;
            f->inicio = f->inicio->prox;
            free(no);
        }
        free(f);
    }
}

int insere_fila(Fila* f, Paciente p) {
    if(f == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = p;
    no->prox = NULL;
    if (f->final == NULL) 
        f->inicio = no;
    else
        f->final->prox = no;
    f->final = no;
    return 1;
}

int remove_fila(Fila* f) {
    if (f == NULL || f->inicio == NULL) return 0; 
    Elem *no = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) 
        f->final = NULL;
    free(no);
    return 1;
}

int fila_vazia(Fila* f) {
    return (f == NULL || f->inicio == NULL);
}

int tamanho_fila(Fila* f) {
    int cont = 0;
    Elem* no = f->inicio;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

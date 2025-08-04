#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    int idade;
    char tipo[10];  // "CORAÇÃO", "CÓRNEA" ou "MEDULA"
    struct Paciente* prox;
} Paciente;

typedef struct Fila {
    Paciente* inicio;
} Fila;

Fila* criaFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    return f;
}

void enfileira(Fila* f, int idade, const char* tipo) {
    Paciente* novo = (Paciente*)malloc(sizeof(Paciente));
    novo->idade = idade;
    strcpy(novo->tipo, tipo);
    novo->prox = NULL;

    // Se a fila está vazia ou o paciente é o mais velho, ele vai para o início
    if (f->inicio == NULL || f->inicio->idade < idade) {
        novo->prox = f->inicio;
        f->inicio = novo;
    } else {
        // Inserção em ordem de prioridade (idade)
        Paciente* atual = f->inicio;
        while (atual->prox != NULL && atual->prox->idade >= idade) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

Paciente* desenfileira(Fila* f) {
    if (f->inicio == NULL) {
        return NULL; // Fila vazia
    }
    Paciente* removido = f->inicio;
    f->inicio = f->inicio->prox;
    return removido;
}

void imprimeFila(Fila* f) {
    Paciente* atual = f->inicio;
    while (atual != NULL) {
        printf("Paciente: %s, Idade: %d\n", atual->tipo, atual->idade);
        atual = atual->prox;
    }
}

void liberaFila(Fila* f) {
    Paciente* atual = f->inicio;
    while (atual != NULL) {
        Paciente* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(f);
}

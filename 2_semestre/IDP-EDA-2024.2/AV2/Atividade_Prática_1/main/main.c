#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fila.h"
#include "lista.h"

#define NUM_INSERCOES 100
#define NUM_REMOCOES 40

const char* gera_tipo_transplante() {
    const char* tipos[] = {"CORAÇÃO", "CÓRNEA", "MEDULA"};
    return tipos[rand() % 3];
}

void tempo_operacoes_fila(Fila* f, double* tempo_insercao, double* tempo_remocao) {
    clock_t inicio, fim;
    double insercao_total = 0, remocao_total = 0;

    for (int i = 0; i < NUM_INSERCOES; i++) {
        Paciente p;
        p.id = i + 1;
        strcpy(p.tipo, gera_tipo_transplante());

        inicio = clock();
        insere_fila(f, p);
        fim = clock();
        insercao_total += (double)(fim - inicio) / CLOCKS_PER_SEC;
    }

    for (int i = 0; i < NUM_REMOCOES; i++) {
        inicio = clock();
        remove_fila(f);
        fim = clock();
        remocao_total += (double)(fim - inicio) / CLOCKS_PER_SEC;
    }

    *tempo_insercao = insercao_total / NUM_INSERCOES;
    *tempo_remocao = remocao_total / NUM_REMOCOES;
}

void tempo_operacoes_lista(Lista* li, double* tempo_insercao, double* tempo_remocao) {
    clock_t inicio, fim;
    double insercao_total = 0, remocao_total = 0;

    for (int i = 0; i < NUM_INSERCOES; i++) {
        Paciente p;
        p.id = i + 1;
        strcpy(p.tipo, gera_tipo_transplante());

        inicio = clock();
        insere_lista(li, p);
        fim = clock();
        insercao_total += (double)(fim - inicio) / CLOCKS_PER_SEC;
    }

    for (int i = 0; i < NUM_REMOCOES; i++) {
        inicio = clock();
        remove_lista(li);
        fim = clock();
        remocao_total += (double)(fim - inicio) / CLOCKS_PER_SEC;
    }

    *tempo_insercao = insercao_total / NUM_INSERCOES;
    *tempo_remocao = remocao_total / NUM_REMOCOES;
}

int main() {
    srand(time(NULL));

    Fila* fila_transplante = cria_fila();
    Lista* lista_transplante = cria_lista();

    double tempo_insercao_fila, tempo_remocao_fila;
    double tempo_insercao_lista, tempo_remocao_lista;

    printf("Operações na FILA:\n");
    tempo_operacoes_fila(fila_transplante, &tempo_insercao_fila, &tempo_remocao_fila);
    printf("Tempo médio de inserção na FILA: %.8f segundos\n", tempo_insercao_fila);
    printf("Tempo médio de remoção na FILA: %.8f segundos\n", tempo_remocao_fila);

    printf("\nOperações na LISTA:\n");
    tempo_operacoes_lista(lista_transplante, &tempo_insercao_lista, &tempo_remocao_lista);
    printf("Tempo médio de inserção na LISTA: %.8f segundos\n", tempo_insercao_lista);
    printf("Tempo médio de remoção na LISTA: %.8f segundos\n", tempo_remocao_lista);

    if (tempo_insercao_fila > tempo_insercao_lista) {
        printf("\nInserção é mais rápida na LISTA.\n");
    } else if (tempo_insercao_fila < tempo_insercao_lista) {
        printf("\nInserção é mais rápida na FILA.\n");
    } else {
        printf("\nTempos de inserção são iguais na FILA e LISTA.\n");
    }

    if (tempo_remocao_fila > tempo_remocao_lista) {
        printf("Remoção é mais rápida na LISTA.\n");
    } else if (tempo_remocao_fila < tempo_remocao_lista) {
        printf("Remoção é mais rápida na FILA.\n");
    } else {
        printf("Tempos de remoção são iguais na FILA e LISTA.\n");
    }

    libera_fila(fila_transplante);
    libera_lista(lista_transplante);

    return 0;
}

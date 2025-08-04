#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
//Samuel Lima Ewald Abrão && João Victor de Genaro Lima
int main() {
    struct aluno al[8] = {
        {1, "Carlos", 7.5, 8.0, 6.5, 7.0, 8.0},
        {2, "Ana", 9.0, 8.5, 9.5, 9.0, 9.0},
        {3, "Bruno", 5.0, 6.5, 6.0, 7.0, 6.0},
        {4, "Mariana", 8.5, 9.0, 8.5, 8.0, 9.0},
        {5, "Paulo", 6.0, 7.0, 6.5, 7.5, 7.0},
        {6, "Julia", 9.5, 9.0, 8.5, 9.5, 9.0},
        {7, "Fernando", 7.0, 6.5, 8.0, 7.5, 7.5},
        {8, "Larissa", 4.5, 3.5, 5.0, 3.0, 6.5}
    };

    Lista *li;
    li = cria_lista();

    for(int i = 0; i < 8; i++) {
        al[i].np = calcular_nota(al[i].n1, al[i].n2, al[i].n3, al[i].n4, al[i].np);
        insere_lista_final(li, al[i]);
    }

    printf("Lista após inserção dos alunos e cálculo das médias:\n");
    imprime_lista(li);

    printf("\nOrdenando a lista por código:\n");
    ordena_lista(li);
    imprime_lista(li);

    struct aluno novo_aluno = {9, "Roberto", 6.0, 5.5, 7.0, 6.5, 7.0};  
    novo_aluno.np = calcular_nota(novo_aluno.n1, novo_aluno.n2, novo_aluno.n3, novo_aluno.n4, novo_aluno.np);
    printf("\nInserindo aluno (codigo 9) de forma ordenada:\n");
    insere_lista_ordenada(li, novo_aluno);
    imprime_lista(li);

    printf("\nRemovendo o primeiro elemento:\n");
    remove_lista_inicio(li);
    imprime_lista(li);

    printf("\nRemovendo o último elemento:\n");
    remove_lista_final(li);
    imprime_lista(li);

    printf("\nRemovendo o aluno de código 5:\n");
    remove_lista_pelo_codigo(li, 5);
    imprime_lista(li);

    int codigo = consulta_lista_pos(li, 2);
    if (codigo) {
        printf("\nO aluno na posição 2 tem o código: %d\n", codigo);
    } else {
        printf("\nPosição inválida.\n");
    }

    int pos = consulta_lista_cod(li, 7);
    if (pos != 0) {
        printf("Aluno com código 7 encontrado na posição: %d\n", pos);
    } else {
        printf("Código 7 não encontrado.\n");
    }

    libera_lista(li);

    return 0;
}

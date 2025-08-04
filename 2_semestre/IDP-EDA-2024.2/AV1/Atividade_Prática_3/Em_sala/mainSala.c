#include <stdio.h>
#include <stdlib.h>
#include "ListaDinSala.h"

int main() {
    Lista* lista_estrutura = cria_lista();
    Lista* lista_fabrica = cria_lista();
    Lista* lista_melhores = cria_lista();       
    Lista* lista_piores = cria_lista();         

    struct aluno estrutura_de_dados[10] = {
        {16350, "Joao", 5.5, 5.5, 5.3, 5.4, 5.0},
        {17890, "Ricardo", 7.0, 8.6, 6.2, 8.4, 8.0},
        {16350, "Bianca", 8.3, 7.2, 8.4, 8.3, 9.0},
        {16350, "Jose", 6.0, 6.1, 6.3, 6.4, 6.0},
        {11234, "Marcelo", 7.0, 7.1, 7.2, 7.0, 7.0},
        {17823, "Fabiano", 8.0, 8.2, 8.3, 8.1, 8.0},
        {16350, "Carla", 6.0, 5.9, 6.1, 6.3, 6.0},
        {17890, "Ana", 9.5, 9.0, 9.1, 9.5, 10.0},
        {12345, "Paulo", 7.5, 7.7, 7.8, 7.5, 8.0},
        {13452, "Gabriel", 8.5, 8.6, 8.7, 8.8, 8.0}
    };

    struct aluno fabrica_de_projetos[10] = {
        {16348, "Fabio", 8.7, 9.7, 5.5, 9.5, 9.0},
        {17980, "Jose", 9.0, 8.8, 8.9, 9.0, 9.0},
        {12343, "Bianca", 5.0, 6.2, 6.5, 6.3, 5.0},
        {15542, "Carlos", 7.5, 7.5, 8.0, 8.1, 8.0},
        {12554, "Joaquim", 9.1, 8.6, 8.5, 9.1, 9.0},
        {15530, "Laura", 6.0, 7.5, 8.1, 7.4, 7.5},
        {12525, "Marcos", 7.7, 7.8, 8.5, 8.6, 8.0},
        {12554, "Lurdes", 8.1, 8.2, 8.3, 8.1, 8.0},
        {12529, "Roberto", 7.5, 8.1, 7.9, 8.0, 8.0},
        {14632, "Samuel", 6.5, 7.0, 6.8, 7.0, 7.5}
    };

    for (int i = 0; i < 10; i++) {
        estrutura_de_dados[i].av = calcular_nota(estrutura_de_dados[i].ap1, estrutura_de_dados[i].ap2, estrutura_de_dados[i].ap3, estrutura_de_dados[i].ap4, estrutura_de_dados[i].np);
        insere_lista_ordenada(lista_estrutura, estrutura_de_dados[i]);
    }

    for (int i = 0; i < 10; i++) {
        fabrica_de_projetos[i].av = calcular_nota(fabrica_de_projetos[i].ap1, fabrica_de_projetos[i].ap2, fabrica_de_projetos[i].ap3, fabrica_de_projetos[i].ap4, fabrica_de_projetos[i].np);
        insere_lista_ordenada(lista_fabrica, fabrica_de_projetos[i]);
    }

    Elem* no = *lista_estrutura;
    while (no != NULL) {
        insere_melhores(lista_melhores, no->dados);   
        insere_piores(lista_piores, no->dados);      
        no = no->prox;
    }

    no = *lista_fabrica;
    while (no != NULL) {
        insere_melhores(lista_melhores, no->dados);    
        insere_piores(lista_piores, no->dados);        
        no = no->prox;
    }
    printf("\nLista de alunos de Estrutura de dados:\n");
    imprime_lista(lista_estrutura);

    printf("\nLista de alunos de Fábrica de projetos 2:\n");
    imprime_lista(lista_fabrica);

    printf("\nLista de 10 Melhores Alunos:\n");
    imprime_lista(lista_melhores);

    printf("\nLista de 10 Piores Alunos:\n");
    imprime_lista(lista_piores);
    libera_lista(lista_estrutura);
    libera_lista(lista_fabrica);
    libera_lista(lista_melhores);
    libera_lista(lista_piores);

    return 0;
}

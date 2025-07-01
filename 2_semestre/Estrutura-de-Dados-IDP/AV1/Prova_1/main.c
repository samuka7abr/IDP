#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "troca.h"

int main() {
    Lista* li = cria_lista();

    insere_lista_final(li, 9);
    insere_lista_final(li, 19);
    insere_lista_final(li, 27);
    insere_lista_final(li, 14);
    insere_lista_final(li, 6);

    printf("Lista original:\n");
    imprime_lista(li);

    int n = 6; 
    printf("\nTrocando o valor %d com o próximo.\n\n", n);
    troca(li, n);

    printf("Lista após troca:\n");
    imprime_lista(li);

    return 0;
}
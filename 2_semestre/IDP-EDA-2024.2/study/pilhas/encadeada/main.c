#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha p;
    inicializa_pilha(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    printf("Pilha após inserções:\n");
    exibir(&p);

    int valor;
    if (peek(&p, &valor)) {
        printf("Topo da pilha: %d\n", valor);
    }

    pop(&p, &valor);
    printf("Elemento removido: %d\n", valor);

    printf("Pilha após remoção:\n");
    exibir(&p);

    return 0;
}

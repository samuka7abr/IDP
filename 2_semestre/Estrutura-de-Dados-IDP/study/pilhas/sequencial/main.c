#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Stack s;
    int valor, opcao;

    start_stack(&s);

    do {
        printf("--SEJA BEM-VINDO AO MENU DE STACK--\n");
        printf("1. Adicionar à pilha\n");
        printf("2. Consultar o topo\n");
        printf("3. Remover do topo\n");
        printf("4. Exibir pilha\n");
        printf("0. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &valor);
                if (push(&s, valor)) {
                    printf("Valor %d adicionado à pilha.\n", valor);
                } else {
                    printf("Pilha cheia. Não foi possível adicionar.\n");
                }
                break;
            case 2:
                if (peek(&s, &valor)) {
                    printf("Topo da pilha: %d\n", valor);
                } else {
                    printf("Pilha vazia.\n");
                }
                break;
            case 3:
                if (pop(&s, &valor)) {
                    printf("Valor %d removido do topo da pilha.\n", valor);
                } else {
                    printf("Pilha vazia. Nada para remover.\n");
                }
                break;
            case 4:
                show(&s);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

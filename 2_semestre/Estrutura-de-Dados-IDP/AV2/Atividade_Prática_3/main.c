#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    int numero, opcao;

    printf("Digite um número decimal: ");
    scanf("%d", &numero);
    printf("Escolha a base de conversão:\n");
    printf("1 - Binário\n");
    printf("2 - Octal\n");
    printf("3 - Hexadecimal\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            converte_base(numero, 2);
            break;
        case 2:
            converte_base(numero, 8);
            break;
        case 3:
            converte_base(numero, 16);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
    return 0;
}

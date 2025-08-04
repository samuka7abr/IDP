#include <stdio.h>

int main() {
    int codigo, quantidade;
    float total = 0;
    char continuar;

    do {
        printf("Digite o código do item pedido: ");
        scanf("%d", &codigo);

        printf("Digite a quantidade: ");
        scanf("%d", &quantidade);

        switch (codigo) {
            case 100:
                total += 5.20 * quantidade;
                break;
            case 101:
                total += 6.30 * quantidade;
                break;
            case 102:
                total += 6.50 * quantidade;
                break;
            case 103:
                total += 7.20 * quantidade;
                break;
            case 104:
                total += 8.30 * quantidade;
                break;
            case 105:
                total += 5.00 * quantidade;
                break;
            default:
                printf("Código inválido\n");
                break;
        }

        printf("Deseja adicionar outro item? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Total a pagar: R$ %.2f\n", total);

    return 0;
}

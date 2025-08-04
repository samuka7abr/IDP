#include <stdio.h>

int main() {
    float salario, parcela;

    printf("Digite o salário do trabalhador: ");
    scanf("%f", &salario);

    printf("Digite o valor da parcela do empréstimo: ");
    scanf("%f", &parcela);

    if (parcela > salario * 0.2) {
        printf("Empréstimo reprovado\n");
    } else {
        printf("Empréstimo aprovado\n");
    }

    return 0;
}

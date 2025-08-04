#include <stdio.h>

int main() {
    char nome[50];
    float salario, valor_emprestimo, parcela;
    int meses;

    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    printf("Digite o salário do cliente: ");
    scanf("%f", &salario);

    printf("Digite o valor do empréstimo: ");
    scanf("%f", &valor_emprestimo);

    printf("Digite o número de meses para quitação: ");
    scanf("%d", &meses);

    parcela = valor_emprestimo / meses;

    if (parcela > salario * 0.2) {
        printf("Empréstimo reprovado\n");
    } else {
        printf("Empréstimo aprovado\n");
    }

    return 0;
}

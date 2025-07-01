#include <stdio.h>

int main() {
    int aprovados = 0, reprovados = 0;

    for (int i = 0; i < 10; i++) {
        char nome[50];
        float salario, valor_emprestimo, parcela;
        int meses;

        printf("Digite o nome do cliente %d: ", i + 1);
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
            reprovados++;
        } else {
            printf("Empréstimo aprovado\n");
            aprovados++;
        }
    }

    printf("Empréstimos aprovados: %d\n", aprovados);
    printf("Empréstimos reprovados: %d\n", reprovados);

    return 0;
}

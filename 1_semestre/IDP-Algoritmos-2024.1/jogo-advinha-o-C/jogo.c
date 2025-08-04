#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numero_secreto, palpite, tentativas;
    char jogar_novamente = 's';

    // Inicializa o gerador de números aleatórios
    srand(time(0));

    while (jogar_novamente == 's' || jogar_novamente == 'S') {
        // Gera um número aleatório entre 1 e 100
        numero_secreto = rand() % 100 + 1;
        tentativas = 0;

        printf("Jogo de Adivinhação!\n");
        printf("Tente adivinhar o número entre 1 e 100.\n");

        do {
            tentativas++;
            printf("Digite seu palpite: ");
            scanf("%d", &palpite);

            if (palpite < numero_secreto) {
                printf("Muito baixo!\n");
            } else if (palpite > numero_secreto) {
                printf("Muito alto!\n");
            } else {
                printf("Parabéns! Você acertou o número em %d tentativas.\n", tentativas);
            }
        } while (palpite != numero_secreto);

        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente);
    }

    printf("Obrigado por jogar!\n");
    return 0;
}


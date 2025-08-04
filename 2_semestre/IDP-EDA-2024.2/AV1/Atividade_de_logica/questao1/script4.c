#include <stdio.h>

int main() {
    int num_atividades = 4;
    float notas[num_atividades];
    float maior_nota = 0, segunda_maior_nota = 0, terceira_maior_nota = 0, quarta_maior_nota = 0;
    float nota_final, nota_prova;

    for (int i = 0; i < num_atividades; i++) {
        printf("Digite a nota da atividade prática %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    for (int i = 0; i < num_atividades; i++) {
        if (notas[i] > maior_nota) {
            quarta_maior_nota = terceira_maior_nota;
            terceira_maior_nota = segunda_maior_nota;
            segunda_maior_nota = maior_nota;
            maior_nota = notas[i];
        } else if (notas[i] > segunda_maior_nota) {
            quarta_maior_nota = terceira_maior_nota;
            terceira_maior_nota = segunda_maior_nota;
            segunda_maior_nota = notas[i];
        } else if (notas[i] > terceira_maior_nota) {
            quarta_maior_nota = terceira_maior_nota;
            terceira_maior_nota = notas[i];
        } else if (notas[i] > quarta_maior_nota) {
            quarta_maior_nota = notas[i];
        }
    }

    printf("\nMaior nota: %.2f\n", maior_nota);
    printf("Segunda maior nota: %.2f\n", segunda_maior_nota);
    printf("Terceira maior nota: %.2f\n", terceira_maior_nota);
    printf("Quarta maior nota: %.2f\n", quarta_maior_nota);

    printf("\nDigite a nota da prova final: ");
    scanf("%f", &nota_prova);

    nota_final = (((maior_nota + segunda_maior_nota + terceira_maior_nota + quarta_maior_nota) / 4) * 0.4) + (nota_prova * 0.6);

    printf("\nA nota final (AV1) do aluno é: %.2f\n", nota_final);

    return 0;
}

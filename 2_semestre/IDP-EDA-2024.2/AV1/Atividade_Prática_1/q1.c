//Escreva um programa que usa uma estrutura capaz de armazenar as notas das atividades práticas e a nota final dos alunos de uma disciplina a partir da seguinte fórmula expressa pela Equação abaixo:( Faça o cadastro de 10 alunos e mostre o resultado.)

#include <stdio.h>
#define NUM_ALUNOS 10

struct Aluno {
    char nome[50];
    float ap1, ap2, ap3, ap4;
    float np;
    float notaFinal;

}; //ao usar struct lembre de sempre encerrar com ";"

int main(){
    struct Aluno alunos[NUM_ALUNOS]; 

    for(int i = 0; i < NUM_ALUNOS; i++){
        printf("Cadastro do aluno %d\n", i + 1);

        printf("Digite a nota da AP1: ");
        scanf("%f", &alunos[i].ap1);
        
        printf("Digite a nota da AP2: ");
        scanf("%f", &alunos[i].ap2);
        
        printf("Digite a nota da AP3: ");
        scanf("%f", &alunos[i].ap3);
        
        printf("Digite a nota da AP4: ");
        scanf("%f", &alunos[i].ap4);
        
        printf("Digite a nota da prova final: ");
        scanf("%f", &alunos[i].np);

        alunos[i].notaFinal = ((alunos[i].ap1 + alunos[i].ap2 + alunos[i].ap3 + alunos[i].ap4) / 4) * 0.4 + (alunos[i].np * 0.6);
    }
    printf("\nResultados Finais:\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Aluno %d: Nota Final = %.2f\n", i + 1, alunos[i].notaFinal);
    }

    return 0;
}

/*
AUTOAVALIAÇÃO:
sinto que o uso de struct facilitou bastante minha forma de programação e acho que estou evoluindo bem na minha lógica.
a colega que me avaliou em sala de aula disse que eu poderia ter usado ponteiros no meu código para que ficasse mais funcional, mas não me senti muito seguro para fazer e não queria fazer pelo chat.
no geral, acho que estou indo bem, ainda tenho muitos pontos a melhorar, mas estou buscando praticar meus pontos fracos.
*/
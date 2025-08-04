/*Faça  uma  narração/fluxo  que  descreva  a  nota  de  um  aluno  a  ser calculada a partir da seguinte fórmula expressa pela Equação abaixo: */
#include <stdio.h>

int main(){
    float n1, n2, n3, n4;
    float np;
    printf("Digite sua nota 1: ");
    scanf("%f", &n1);
    printf("Digite sua nota 2: ");
    scanf("%f", &n2);
    printf("Digite sua nota 3: ");
    scanf("%f", &n3);
    printf("Digite sua nota 4: ");
    scanf("%f", &n4);
    printf("Digite sua nota P: ");
    scanf("%f", &np);
    float nota1 = ((n1 + n2 + n3 + n4)/4)*0.4;
    float nota2 = (np*0.6);
    float notafinal = nota1 + nota2;
    printf("Nota final: %.2f", notafinal);
return 0;
}
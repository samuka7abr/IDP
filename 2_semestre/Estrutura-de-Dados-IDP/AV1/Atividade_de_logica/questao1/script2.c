/*Faça uma narração/fluxo que leia o salário de um funcionário. Calcule e 
imprima o valor do novo salário, sabendo que ele recebeu um aumento 
de 25%.*/
#include <stdio.h>

int main(){
    float salario;
    printf("Digite seu salário:");
    scanf("%f", &salario);
    float novoSalario = salario*1.25;
    printf("Seu novo salário: %.2f", novoSalario);
    
return 0;
}
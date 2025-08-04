/*Faça uma narração/fluxo que leia um valor em real e a cotação do dólar. 
Em seguida, imprima o valor correspondente em dólares.*/
#include <stdio.h>

int main(){
    float valor;
    float cotacao;
    
    printf("Bem vindo ao conversor de dólar!\n");
    printf("Digite o valor da em reais que deseja converter: ");
    scanf("%f", &valor);
    printf("Agora digite a cotação do dólar: ");
    scanf("%f", &cotacao);
     float valor_convertido = valor*cotacao;
    printf("Valor convertido: %.2f", valor_convertido);
    
return 0;
}
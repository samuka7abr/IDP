#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
   float num1, num2;
   char operador;
   char continuar = 's';
   
   while (continuar == 's' || continuar == 'S') {
       printf("\nDigite o primeiro número: ");
       scanf("%f", &num1);
   
       printf("\nDigite o segundo número: ");
       scanf("%f", &num2);
   
       printf("\nDigite a operação desejada: (+, -, *, /): ");
       scanf(" %c", &operador);
   
       switch (operador) {
           case '+':
               printf("\nResultado: %.2f\n", num1 + num2);
               break;
           case '-':
               printf("\nResultado: %.2f\n", num1 - num2);
               break;
           case '*':
               printf("\nResultado: %.2f\n", num1 * num2);
               break;
           case '/':
               if (num2 != 0) {
                   printf("\nResultado: %.2f\n", num1 / num2);
               } else {
                   printf("\nErro: Divisão por 0 não é permitida\n");
               }
               break;
           default:
               printf("\nOperador inválido\n");
       }
   
       printf("\nDeseja realizar outra operação? (s/n): ");
       scanf(" %c", &continuar);
   }
  
   printf("\nSaindo da Calculadora...\n");
   return 0;
}


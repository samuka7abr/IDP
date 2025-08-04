/*Simulação de empréstimo: Escreva um programa que usa uma estrutura capaz de armazenar dados de solicitações de empréstimos de clientes de um banco. O programa deve ler os seguintes dados: nome do cliente, salário do cliente, o valor do empréstimo e o número de meses para quitação. Simule a solicitação de 10 empréstimos. No final, imprima a quantidade de empréstimos concedidos e a quantidade de empréstimos não concedidos.

- O programa deve calcular o valor da parcela do empréstimo requerido.
- Se o valor da parcela for maior que 20% do salário, o empréstimo será reprovado, caso contrário, o empréstimo será aprovado.*/

#include <stdio.h>
#define NUM_CLIENTES 10

struct Cliente{
    char nome[50];
    float salario;
    float emprestimo;
    int meses;
};
int main(){
    struct Cliente clientes[NUM_CLIENTES];
    int aprovados = 0, reprovados = 0;
    
    for(int i = 0; i < NUM_CLIENTES; i++){
        printf("\nCadastro do cliente %d\n", i + 1);

        printf("Digite o nome do Cliente: ");
        scanf("%49s", &clientes[i].nome);
        
        printf("Digite o salário do cliente: ");
        scanf("%f", &clientes[i].salario);

        printf("Digite o valor do empréstimo: ");
        scanf("%f", &clientes[i].emprestimo);

        printf("Digite o número de meses para quitação: ");
        scanf("%d", &clientes[i].meses);    

        float parcela = clientes[i].emprestimo / clientes[i].meses;
        
        if (parcela > clientes[i].salario * 0.2){
            printf("\nEmpréstimo não aprovado para o cliente: %s\n", clientes[i].nome);
            reprovados++;
           }
        else{
             printf("\nEmpréstimo autorizado para o Cliente: %s \n", clientes[i].nome);
            aprovados++;
        }
    


    }   
    printf("Número de empréstimos aprovados: %d\n", aprovados);
    printf("\nNúmero de empréstimos reprovados: %d\n", reprovados);
    
    return 0;

}
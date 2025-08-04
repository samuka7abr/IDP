//3. Pedidos: Escreva um programa que usa estruturas capaz de armazenar os pedidos dos clientes.II. Simule 10 pedidos. No final, imprima o faturamento do dia.

#include <stdio.h>

#define NUM_PRODUTOS 6
#define NUM_PEDIDOS 10

struct Produto {
    int codigo;
    char descricao[50];
    float preco;
};

struct ItemPedido {
    int codigo_produto;
    int quantidade;
};

struct Pedido {
    struct ItemPedido itens[NUM_PRODUTOS];  
    int num_itens;
};

int main() {
    struct Produto cardapio[NUM_PRODUTOS] = {
        {100, "Cachorro-quente", 5.20},
        {101, "Bauru simples", 6.30},
        {102, "Bauru com ovo", 6.50},
        {103, "Hambúrguer", 7.20},
        {104, "Cheeseburger", 8.30},
        {105, "Refrigerante", 5.00}
    };

    struct Pedido pedidos[NUM_PEDIDOS];
    float faturamento_total = 0.0;

    for (int i = 0; i < NUM_PEDIDOS; i++) {
        pedidos[i].num_itens = 0;  

        printf("Pedido %d\n", i + 1);
        char continuar;
        do {
            printf("Digite o código do produto: ");
            scanf("%d", &pedidos[i].itens[pedidos[i].num_itens].codigo_produto);

            printf("Digite a quantidade: ");
            scanf("%d", &pedidos[i].itens[pedidos[i].num_itens].quantidade);

            pedidos[i].num_itens++;  
            printf("Deseja adicionar mais um item ao pedido? (s/n): ");
            scanf(" %c", &continuar);

        } while (continuar == 's' || continuar == 'S');
    }

    for (int i = 0; i < NUM_PEDIDOS; i++) {
        float total_pedido = 0.0;

        for (int j = 0; j < pedidos[i].num_itens; j++) {
            int codigo = pedidos[i].itens[j].codigo_produto;
            int quantidade = pedidos[i].itens[j].quantidade;

            for (int k = 0; k < NUM_PRODUTOS; k++) {
                if (cardapio[k].codigo == codigo) {
                    total_pedido += cardapio[k].preco * quantidade;
                    break;
                }
            }
        }

        faturamento_total += total_pedido;
        printf("Total do pedido %d: R$ %.2f\n", i + 1, total_pedido);
    }

    printf("\nFaturamento total do dia: R$ %.2f\n", faturamento_total);

    return 0;
}

/*Cardápio: 
| Índice | Especificação   | Código | Preço   |
| ------ | --------------- | ------ | ------- |
| 1      | Cachorro-quente | 100    | R$ 5.20 |
| 2      | Bauru simples   | 101    | R$ 6.30 |
| 3      | Bauru com ovo   | 102    | R$ 6.50 |
| 4      | Hambúrguer      | 103    | R$ 7.20 |
| 5      | Cheeseburger    | 104    | R$ 8.30 |
| 6      | Refrigerante    | 105    | R$ 5.00 |
*/
/*
AUTOAVALIAÇÃO:
sinto que o uso de struct facilitou bastante minha forma de programação e acho que estou evoluindo bem na minha lógica.
a colega que me avaliou em sala de aula disse que eu poderia ter usado ponteiros no meu código para que ficasse mais funcional, mas não me senti muito seguro para fazer e não queria fazer pelo chat.
no geral, acho que estou indo bem, ainda tenho muitos pontos a melhorar, mas estou buscando praticar meus pontos fracos.
*/
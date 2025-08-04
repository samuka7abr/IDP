#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "estrutura.h"

void exibir_menu() {
    printf("\n--- Sistema de Gerenciamento de Transplantes ---\n");
    printf("1. Adicionar doação\n");
    printf("2. Processar doação\n");
    printf("3. Exibir estado das estruturas\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

// Mapeia as capitais e atribui um ID para cada uma
void exibir_capitais() {
    const char* capitais[] = {
        "Rio Branco", "Porto Velho", "Manaus", "Boa Vista", "Belém", 
        "Macapá", "Palmas", "São Luís", "Teresina", "Fortaleza", 
        "Natal", "João Pessoa", "Recife", "Maceió", "Aracaju", 
        "Salvador", "Brasília", "Goiânia", "Cuiabá", "Campo Grande", 
        "Belo Horizonte", "Vitória", "Rio de Janeiro", "São Paulo", 
        "Curitiba", "Florianópolis", "Porto Alegre"
    };

    printf("\n--- Capitais e seus IDs ---\n");
    // For para percorrer o array de estados e numerar cada um
    for (int i = 0; i < 27; i++) {
        printf("ID: %d - %s\n", i, capitais[i]);
    }
    printf("---------------------------\n");
}

// Encontra o CD mais próximo
int encontrar_cd_bfs(Grafo* grafo, int origem, int* cds, int n_cds, int* pais) {
    return bfs(grafo, origem, cds, n_cds, pais);
}

int encontrar_cd_dfs(Grafo* grafo, int origem, int* cds, int n_cds, int* pais) {
    int visitados[grafo->nro_vertices];
    int resultado[grafo->nro_vertices];
    int index = 0;

    memset(visitados, 0, sizeof(visitados));
    memset(pais, -1, grafo->nro_vertices * sizeof(int));

    dfs(grafo, origem, visitados, resultado, &index, cds, n_cds, pais);
    return index > 0 ? resultado[0] : -1;
}

int main() {
    const char* capitais[] = {
        "Rio Branco", "Porto Velho", "Manaus", "Boa Vista", "Belém", 
        "Macapá", "Palmas", "São Luís", "Teresina", "Fortaleza", 
        "Natal", "João Pessoa", "Recife", "Maceió", "Aracaju", 
        "Salvador", "Brasília", "Goiânia", "Cuiabá", "Campo Grande", 
        "Belo Horizonte", "Vitória", "Rio de Janeiro", "São Paulo", 
        "Curitiba", "Florianópolis", "Porto Alegre"
    };

    // Dá início ao grafo com 27 vértices
    int n_capitais = 27; 
    Grafo* grafo = cria_grafo(n_capitais);
    
    //conexões entre os vértices
    adiciona_aresta(grafo, 0, 2);   //Rio Branco -> Manaus
    adiciona_aresta(grafo, 1, 2);   //Porto Velho -> Manaus
    adiciona_aresta(grafo, 2, 0);   //Manaus -> Rio Branco
    adiciona_aresta(grafo, 2, 1);   //Manaus -> Porto Velho
    adiciona_aresta(grafo, 2, 3);   //Manaus -> Boa Vista
    adiciona_aresta(grafo, 3, 2);   //Boa Vista -> Manaus
    adiciona_aresta(grafo, 3, 4);   //Boa Vista -> Belém
    adiciona_aresta(grafo, 4, 3);   //Belém -> Boa Vista
    adiciona_aresta(grafo, 4, 5);   //Belém -> Macapá
    adiciona_aresta(grafo, 4, 6);   //Belém -> Brasília
    adiciona_aresta(grafo, 4, 7);   //Belém -> São Luís
    adiciona_aresta(grafo, 5, 4);   //Macapá -> Belém
    adiciona_aresta(grafo, 7, 4);   //São Luís -> Belém
    adiciona_aresta(grafo, 7, 9);   //São Luís -> Fortaleza
    adiciona_aresta(grafo, 7, 8);   //São Luís -> Teresina
    adiciona_aresta(grafo, 7, 6);   //São Luís -> Palmas
    adiciona_aresta(grafo, 9, 7);   //Fortaleza -> São Luís
    adiciona_aresta(grafo, 9, 10);  //Fortaleza -> Natal
    adiciona_aresta(grafo, 9, 6);   //Fortaleza -> Brasília
    adiciona_aresta(grafo, 10, 9);  //Natal -> Fortaleza
    adiciona_aresta(grafo, 10, 11); //Natal -> João Pessoa
    adiciona_aresta(grafo, 11, 10); //João Pessoa -> Natal
    adiciona_aresta(grafo, 11, 12); //João Pessoa -> Recife
    adiciona_aresta(grafo, 12, 11); //Recife -> João Pessoa
    adiciona_aresta(grafo, 12, 13); //Recife -> Maceió
    adiciona_aresta(grafo, 13, 12); //Maceió -> Recife
    adiciona_aresta(grafo, 13, 14); //Maceió -> Aracaju
    adiciona_aresta(grafo, 14, 13); //Aracaju -> Maceió
    adiciona_aresta(grafo, 14, 15); //Aracaju -> Salvador
    adiciona_aresta(grafo, 15, 14); //Salvador -> Aracaju
    adiciona_aresta(grafo, 15, 6);  //Salvador -> Brasília
    adiciona_aresta(grafo, 8, 7);   //Teresina -> São Luís
    adiciona_aresta(grafo, 8, 6);   //Teresina -> Palmas
    adiciona_aresta(grafo, 6, 4);   //Palmas -> Belém
    adiciona_aresta(grafo, 6, 7);   //Palmas -> São Luís
    adiciona_aresta(grafo, 6, 8);   //Palmas -> Teresina
    adiciona_aresta(grafo, 6, 9);   //Palmas -> Brasília
    adiciona_aresta(grafo, 6, 15);  //Palmas -> Salvador
    adiciona_aresta(grafo, 6, 16);  //Palmas -> Belo Horizonte
    adiciona_aresta(grafo, 16, 6);  //Brasília -> Palmas
    adiciona_aresta(grafo, 16, 17); //Brasília -> Goiânia
    adiciona_aresta(grafo, 16, 18); //Brasília -> Cuiabá
    adiciona_aresta(grafo, 16, 20); //Brasília -> Belo Horizonte
    adiciona_aresta(grafo, 16, 23); //Brasília -> São Paulo
    adiciona_aresta(grafo, 17, 16); //Goiânia -> Brasília
    adiciona_aresta(grafo, 17, 19); //Goiânia -> Campo Grande
    adiciona_aresta(grafo, 19, 17); //Campo Grande -> Goiânia
    adiciona_aresta(grafo, 19, 18); //Campo Grande -> Cuiabá
    adiciona_aresta(grafo, 19, 23); //Campo Grande -> São Paulo
    adiciona_aresta(grafo, 18, 19); //Cuiabá -> Campo Grande
    adiciona_aresta(grafo, 18, 16); //Cuiabá -> Brasília
    adiciona_aresta(grafo, 20, 16); //Belo Horizonte -> Brasília
    adiciona_aresta(grafo, 20, 21); //Belo Horizonte -> Vitória
    adiciona_aresta(grafo, 20, 22); //Belo Horizonte -> Rio de Janeiro
    adiciona_aresta(grafo, 20, 23); //Belo Horizonte -> São Paulo
    adiciona_aresta(grafo, 21, 20); //Vitória -> Belo Horizonte
    adiciona_aresta(grafo, 22, 20); //Rio de Janeiro -> Belo Horizonte
    adiciona_aresta(grafo, 22, 23); //Rio de Janeiro -> São Paulo
    adiciona_aresta(grafo, 23, 16); //São Paulo -> Brasília
    adiciona_aresta(grafo, 23, 20); //São Paulo -> Belo Horizonte
    adiciona_aresta(grafo, 23, 19); //São Paulo -> Campo Grande
    adiciona_aresta(grafo, 23, 24); //São Paulo -> Curitiba
    adiciona_aresta(grafo, 24, 23); //Curitiba -> São Paulo
    adiciona_aresta(grafo, 24, 25); //Curitiba -> Florianópolis
    adiciona_aresta(grafo, 25, 24); //Florianópolis -> Curitiba
    adiciona_aresta(grafo, 25, 26); //Florianópolis -> Porto Alegre
    adiciona_aresta(grafo, 26, 25); //Porto Alegre -> Florianópolis


    // Atribui os centros de distribuição pelo ID
    int cds[] = {9, 16, 23}; // Fortaleza, Brasília, São Paulo
    int n_cds = sizeof(cds) / sizeof(cds[0]);

    // Cria as pilhas e filas de cada CD
    Pilha* pilhaBrasilia = cria_pilha();
    Pilha* pilhaFortaleza = cria_pilha();
    Pilha* pilhaSaoPaulo = cria_pilha();

    Fila* filaBrasilia = cria_fila();
    Fila* filaFortaleza = cria_fila();
    Fila* filaSaoPaulo = cria_fila();
    
    // Lista global pra mostrar todos os órgãos presentes nos CD's
    ListaGlobal* listaGlobal = cria_lista_global();

    // Vetor para armazenar os pais na busca
    int pais_bfs[n_capitais];
    int pais_dfs[n_capitais];


    // Do while para controlar as opções do menu
    int opcao;
    do {
        exibir_menu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            exibir_capitais();
            int origem;
            char tipo[20];
            printf("Digite o ID da capital de origem (0 a 26): ");
            scanf("%d", &origem);

            printf("Digite o tipo de órgão (CORAÇÃO, MEDULA, CÓRNEA): ");
            scanf("%s", tipo);

            Orgao* novo_orgao = (Orgao*) malloc(sizeof(Orgao));
            novo_orgao->id = rand() % 1000;
            strcpy(novo_orgao->tipo, tipo);
            sprintf(novo_orgao->origem, "Capital %d", origem);
            strcpy(novo_orgao->status, "Em espera para transplante");

            // BFS
            int cd_bfs = encontrar_cd_bfs(grafo, origem, cds, n_cds, pais_bfs);

            // DFS
            int cd_dfs = encontrar_cd_dfs(grafo, origem, cds, n_cds, pais_dfs);

            printf("\nCaminho percorrido (BFS): ");
            exibir_caminho(pais_bfs, origem, cd_bfs, capitais);

            printf("\nCaminho percorrido (DFS): ");
            exibir_caminho(pais_dfs, origem, cd_dfs, capitais);

            printf("\n");

            // Adiciona o órgão no CD mais próximo
            if (strcmp(tipo, "CORAÇÃO") == 0) {
                if (cd_bfs == 16) adiciona_pilha(pilhaBrasilia, novo_orgao);
                else if (cd_bfs == 9) adiciona_pilha(pilhaFortaleza, novo_orgao);
                else if (cd_bfs == 23) adiciona_pilha(pilhaSaoPaulo, novo_orgao);
            } else {
                if (cd_bfs == 16) adiciona_fila(filaBrasilia, novo_orgao);
                else if (cd_bfs == 9) adiciona_fila(filaFortaleza, novo_orgao);
                else if (cd_bfs == 23) adiciona_fila(filaSaoPaulo, novo_orgao);
            }

            adiciona_lista_global(listaGlobal, novo_orgao);
            printf("Doação adicionada com sucesso.\n");
        } else if (opcao == 2) {
            printf("Escolha o CD para processar a doação (1 - Brasília, 2 - Fortaleza, 3 - São Paulo): ");
            int cd;
            scanf("%d", &cd);
            Orgao* orgao_removido = NULL;

            if (cd == 1) {
                orgao_removido = pilha_vazia(pilhaBrasilia) ? remove_fila(filaBrasilia) : remove_pilha(pilhaBrasilia);
            } else if (cd == 2) {
                orgao_removido = pilha_vazia(pilhaFortaleza) ? remove_fila(filaFortaleza) : remove_pilha(pilhaFortaleza);
            } else if (cd == 3) {
                orgao_removido = pilha_vazia(pilhaSaoPaulo) ? remove_fila(filaSaoPaulo) : remove_pilha(pilhaSaoPaulo);
            }

            if (orgao_removido) {
                printf("Órgão do tipo %s processado com sucesso.\n", orgao_removido->tipo);
                free(orgao_removido);
            } else {
                printf("Nenhum órgão disponível.\n");
            }
        } else if (opcao == 3) {
            printf("\n--- Brasília ---\n");
            exibe_pilha(pilhaBrasilia);
            exibe_fila(filaBrasilia);

            printf("\n--- Fortaleza ---\n");
            exibe_pilha(pilhaFortaleza);
            exibe_fila(filaFortaleza);

            printf("\n--- São Paulo ---\n");
            exibe_pilha(pilhaSaoPaulo);
            exibe_fila(filaSaoPaulo);

            printf("\n--- Lista Global ---\n");
            exibe_lista_global(listaGlobal);
        }
    } while (opcao != 4);

    libera_pilha(pilhaBrasilia);
    libera_pilha(pilhaFortaleza);
    libera_pilha(pilhaSaoPaulo);
    libera_fila(filaBrasilia);
    libera_fila(filaFortaleza);
    libera_fila(filaSaoPaulo);
    libera_lista_global(listaGlobal);
    libera_grafo(grafo);

    printf("Sistema encerrado.\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncadeada.h"

int main() {
    Lista* li = cria_lista();
    int opcao = 0;

    while (opcao != 4) {
        printf("==============================\n");
        printf("== Seja bem-vindo ao gerenciador de alunos ==\n");
        printf("Digite a opção desejada:\n");
        printf("1- Adicionar aluno\n");
        printf("2- Remover aluno\n");
        printf("3- Consultar alunos\n");
        printf("4- Sair\n");
        printf("==============================\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: { 
                struct aluno al;
                printf("Digite o código do aluno: ");
                scanf("%d", &al.codigo);
                
                printf("Digite o nome do aluno: ");
                getchar(); 
                fgets(al.nome, 50, stdin);
                size_t ln = strlen(al.nome) - 1;
                if (al.nome[ln] == '\n') {
                    al.nome[ln] = '\0';
                }

                printf("Digite as notas (n1, n2, n3, n4): ");
                scanf("%f %f %f %f", &al.n1, &al.n2, &al.n3, &al.n4);
                printf("Digite a nota da prova final: ");
                scanf("%f", &al.np);

                insere_lista_ordenada(li, al);
                printf("Aluno adicionado com sucesso!\n");
                break;
            }
            case 2: { 
                int opcao_remover;
                printf("Escolha como deseja remover:\n");
                printf("1- Remover primeiro aluno\n");
                printf("2- Remover último aluno\n");
                printf("3- Remover aluno pelo código\n");
                scanf("%d", &opcao_remover);

                if (opcao_remover == 1) {
                    if (remove_lista_inicio(li)) {
                        printf("Primeiro aluno removido com sucesso!\n");
                    } else {
                        printf("Erro ao remover o primeiro aluno.\n");
                    }
                } else if (opcao_remover == 2) {
                    if (remove_lista_final(li)) {
                        printf("Último aluno removido com sucesso!\n");
                    } else {
                        printf("Erro ao remover o último aluno.\n");
                    }
                } else if (opcao_remover == 3) {
                    int codigo;
                    printf("Digite o código do aluno a ser removido: ");
                    scanf("%d", &codigo);
                    if (remove_lista_pelo_codigo(li, codigo)) {
                        printf("Aluno removido com sucesso!\n");
                    } else {
                        printf("Erro ao remover aluno. Código não encontrado.\n");
                    }
                }
                break;
            }
            case 3: { 
                int opcao_consulta;
                printf("Escolha como deseja consultar:\n");
                printf("1- Mostrar todos os alunos\n");
                printf("2- Consultar aluno pelo código\n");
                scanf("%d", &opcao_consulta);

                if (opcao_consulta == 1) {
                    imprime_lista(li);
                    if (li == NULL){printf("Nenhum aluno cadastrado!");}
                } else if (opcao_consulta == 2) {
                    int codigo;
                    printf("Digite o código do aluno: ");
                    scanf("%d", &codigo);
                    if (!consulta_lista_cod(li, codigo)) {
                        printf("Aluno com código %d não encontrado.\n", codigo);
                    }
                }
                break;
            }
            case 4: {
                libera_lista(li);
                printf("Programa encerrado.\n");
                break;
            }
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}

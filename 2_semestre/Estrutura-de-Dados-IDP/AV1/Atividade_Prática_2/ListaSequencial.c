//ARQUIVO ListaSequencial.c
#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct lista{
    int qtd; // Quantas posicoes ja foram ocupadas?
    struct aluno dados[MAX];
};

// Retorna um ponteiro para a lista com a estrutura inicializada
Lista* cria_lista()
{
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void libera_lista(Lista* li)
{
    free(li);
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX); // Se igual a MAX returno 1, sen�o returno 0
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0); // Se qtd igual a 0 returno 1, sen�o returno 0
}

void imprime_pirocasta(Lista* li) {
    if (li == NULL)
        return;
    int i;
    for (i = 0; i < li->qtd; i++) {
        
        float media_final = calcular_nota(li->dados[i].n1, li->dados[i].n2, li->dados[i].n3, li->dados[i].n4, li->dados[i].np);

        printf("Codigo: %d\n", li->dados[i].codigo);
        printf("Nome: %s\n", li->dados[i].nome);
        printf("Notas Ap: %.2f - %.2f - %.2f - %.2f\n", 
               li->dados[i].n1, 
               li->dados[i].n2, 
               li->dados[i].n3, 
               li->dados[i].n4);  
        printf("Nota Prova:: %.2f\n", li->dados[i].np);
        printf("Média Final: %.2f\n", media_final);
        printf("-------------------------------\n");
    }
}



int insere_lista_vazia(Lista* li, struct aluno al)
{
    if(li == NULL)
        return 0;
    li->dados[0] = al; // Armazena na 1� posicao...
    li->qtd++;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

// � necessario deslocamento
int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    int i;
    //if (lista_vazia(li))
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
    
}


//Funções criadas por mim a partir daqui:


int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL || lista_cheia(li)) {
        return 0; //erro ao inserir
    }
    int i = 0;
    while (i < li->qtd && li->dados[i].codigo < al.codigo) {
        i++;
    }

    for (int k = li->qtd - 1; k >= i; k--) {
        li->dados[k + 1] = li->dados[k]; 
    }

    li->dados[i] = al;
    li->qtd++;

    return 1; //sucesso ao inserir
}

int remove_lista_inicio(Lista* li){
    if (li == NULL || lista_vazia(li)){
        return 0;
    }
    for(int i = 0; i < li->qtd - 1; i++){
        li->dados[i] = li->dados[i + 1];
    }
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL || lista_vazia(li)){
        return 0;
    }
    li->qtd--;
    return 1;
}
int remove_lista_pelo_codigo(Lista* li, int cod){
    if(li == NULL || lista_vazia(li)){
        return 0;
    }
    int i = 0;
    while(i < li->qtd && li->dados[i].codigo != cod){
        i++;
    }
    if(i == li->qtd){
        return 0;
    }
    for (int k = i; k < li->qtd - 1; k++){
        li->dados[k] = li->dados[k + 1];
    }
    li->qtd--;

    return 1;
}
int consulta_lista_pos(Lista* li, int ind){
    if(li == NULL || lista_vazia(li)){
        return 0;
    }
    
    for(int i = 0; i < li->qtd; i++){
        if(i == ind){
            return li->dados[ind].codigo;
        }
    }
    return 0;
}

int consulta_lista_cod(Lista* li, int cod) {
    if (li == NULL || lista_vazia(li)) {
        return 0; 
    }

    for (int i = 0; i < li->qtd; i++) {
        if (li->dados[i].codigo == cod) {
            return i;  
        }
    }
    return 0;  
}


//função de sort
void ordena_lista(Lista* li) {
    if (li == NULL || lista_vazia(li)) {
        return;
    }

    struct aluno temp;  
    int i, j;
    for (i = 0; i < li->qtd - 1; i++) {
        for (j = 0; j < li->qtd - 1 - i; j++) {
            if (li->dados[j].codigo > li->dados[j + 1].codigo) {
                temp = li->dados[j];
                li->dados[j] = li->dados[j + 1];
                li->dados[j + 1] = temp;
            }
        }
    }
}

float calcular_nota(float n1, float n2, float n3, float n4, float nota_prova) {
    float media_parcial = (n1 + n2 + n3 + n4) / 4; 
    float media_final = (media_parcial * 0.4) + (nota_prova * 0.6); 
    return media_final;
}


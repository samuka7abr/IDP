#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "troca.h"


int troca(Lista *li, int n){
    if(li == NULL || *li == NULL){return 0;} //verifica se a lista é nula ou o ponteiro da lista é nulo (retorna 0 caso sim)

    Elem *ant = NULL, *atual = *li; //declaração dos ponteiros que percorrem a lista (two pointer)

    do //enquanto a lista não for percorrida até o início (condição do while)
    {
        if(atual->valor == n) break;  //caso encontre o elemento n, sai do laço
        ant = atual; //atualiza o ponteiro ant para ser o novo atual e move o ponteiro atual para o proximo nó da lista
        atual = atual->prox;

    } while (atual != *li); //dá uma volta completa na lista

    if(atual->valor != n){return 0;} //caso não ache o valor n, retorna 0

    if(atual == atual->prox){return 0;}  //verifica se a lista tem apenas um elemento. caso tenha, não tem o que trocar, entaõ retorna 0

    Elem* prox = atual->prox; //o ponteiro prox aponta para o último elemento da lista que vai ser trocado de posição com o ponteiro atual
    if(prox == *li){ //verifica a circularidade da lista (ve se o ultimo elemento ta apontando pro primeiro)
        *li = atual;
    }

    atual->prox = prox->prox; //faz a troca de posição entreo ponteiro atal->prox e o ponteiro prox (atual->prox agora aponta para prox)
    //prox->prox agora aponta para atual (passando a vir antes de atual)
    prox->prox = atual;

    if(ant != NULL) {
        ant->prox = prox;
    }else{
        //ajusta a cabeça da lista para o novo primeiro elemento
        Elem* aux = *li;
    
        //percorre a lista para encontrar o último elemento
        while(aux->prox != *li) {
            aux = aux->prox;
        }

        //atualiza o último elemento para apontar para o novo primeiro
        aux->prox = prox;
    
        //atualiza o ponteiro da cabeça da lista
        *li = prox;
    }   
    return 1; //retorna 1 caso sucesso


    //criei um main que testasse o valor de N percorrendo todos os elementos da lista permutando todos eles (deu certo) e não apresentou nenhum erro no debug, logo, essa é a versão final
}
 
#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
int main(){
    int eh_digrafo = 1;

    //main.c
    Grafo* gr = cria_Grafo(10, 7, 1);

    // main.c
    insereAresta(gr, 0, 1, 0, 3);
    insereAresta(gr, 1, 3, 0, 2);
    insereAresta(gr, 3, 2, 0, 4);
    insereAresta(gr, 6, 1, 0, 1);

    //insereAresta(gr, 3, 0, 0, 0);
    //insereAresta(gr, 3, 4, 0, 0);
    //insereAresta(gr, 4, 1, 0, 0);

    imprime_Grafo(gr);
    //imprime_Grau(gr);

    // printf("\nBusca \n");
    // int vis[5];
    //buscaProfundidade_Grafo(gr, 0, vis);
    //buscaLargura_Grafo(gr, 0, vis);

    // int i,ant[5];
    // float dist[5];
    // menorCaminho_Grafo(gr, 0, ant, dist);
    // for(i=0; i<5; i++)
    //     printf("%d: %d -> %f\n",i,ant[i],dist[i]);

    libera_Grafo(gr);

    return 0;
}

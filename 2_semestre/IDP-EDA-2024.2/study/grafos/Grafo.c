#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h" // Prototipos

// Estrutura para representar um nó na lista de adjacência
struct vertice {
    int destino;
    float peso;
    struct vertice* prox;
};

struct listaArestas{
    struct vertice* head;
};

// Definicao do tipo Grafo
struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    struct listaArestas* arestas;
    int* grau;
};

// Função para criar um novo vertice na lista de adjacência
Vertice* criarVertice(int destino) {
    Vertice* novoVertice    = (Vertice*) malloc(sizeof(struct vertice));
    if(novoVertice != NULL){
        novoVertice->destino    = destino;
        novoVertice->prox       = NULL;
    }
    return novoVertice;
}

// grafo.c
Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices    = nro_vertices;
        gr->grau_max        = grau_max;
        gr->eh_ponderado    = eh_ponderado;
        gr->grau = (int*) calloc(nro_vertices, sizeof(int));

        gr->arestas = (struct listaArestas*) malloc(nro_vertices * sizeof(struct listaArestas));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i].head = NULL;
    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++){
            Vertice* temp = gr->arestas[i].head;
            while (temp != NULL) {
                Vertice* proximo = temp->prox;
                free(temp);
                temp = proximo;
            }
        }
        free(gr->arestas);
        free(gr->grau);
        free(gr);
    }
}

// Grafo.c
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    Vertice* novoVert = criarVertice(dest);
    novoVert->prox = gr->arestas[orig].head;
    if(gr->eh_ponderado)
        novoVert->peso = peso;
    gr->arestas[orig].head = novoVert;

    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    Vertice* temp = gr->arestas[orig].head;
    Vertice* prev = NULL;

    // Remover a aresta de origem para destino
    int i=0;
    while (temp != NULL && temp->destino != dest) {
        prev = temp;
        temp = temp->prox;
        i++;
    }

    if (temp != NULL){
        if (prev != NULL) {
            prev->prox = temp->prox;
        } else {
            gr->arestas[orig].head = temp->prox;
        }
        free(temp);      
        gr->grau[orig]--;  

        if(eh_digrafo == 0)
            removeAresta(gr,dest,orig,1);

        return 1;
    }
    return 0;
}

void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i=0, j=0;
    for(i; i < gr->nro_vertices; i++){
        Vertice* vi = gr->arestas[i].head;
        printf("%d: ", i);
        while(vi){
            if (gr->eh_ponderado)
                printf("-> %d(%.2f) ", vi->destino, vi->peso);
            else
                printf("-> %d ", vi->destino);
            vi = vi->prox;
            j++;
        }
        printf("\n");
    }
}

void imprime_Grau(Grafo *gr){
    if(gr == NULL)
        return;

    int i=0, j=0;
    printf("\nGrau dos vertices\n");
    for(i; i < gr->nro_vertices; i++)
        printf("Vertice %d: %d\n", i, gr->grau[i]);
}

/*
Algoritmos para Grafos em C
 via Sedgewick
http://www.ime.usp.br/~pf/algoritmos_para_grafos/
*/
// https://www.cs.auckland.ac.nz/software/AlgAnim/dijkstra.html
// http://www.cprogramming.com/tutorial/computersciencetheory/dijkstra.html
// int procuraMenorDistancia(float *dist, int *visitado, int NV){
//     int i, menor = -1, primeiro = 1;
//     for(i=0; i < NV; i++){
//         if(dist[i] >= 0 && visitado[i] == 0){
//             if(primeiro){
//                 menor = i;
//                 primeiro = 0;
//             }else{
//                 if(dist[menor] > dist[i])
//                     menor = i;
//             }
//         }
//     }
//     return menor;
// }

// void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist){
//     int i, cont, NV, ind, *visitado, vert;
//     cont = NV = gr->nro_vertices;
//     visitado = (int*) malloc(NV * sizeof(int));
//     for(i=0; i < NV; i++){
//         ant[i] = -1;
//         dist[i] = -1;
//         visitado[i] = 0;
//     }
//     dist[ini] = 0;
//     while(cont > 0){
//         vert = procuraMenorDistancia(dist, visitado, NV);
//         //printf("u = %d\n",u);
//         if(vert == -1)
//             break;

//         visitado[vert] = 1;
//         cont--;
//         for(i=0; i<gr->grau[vert]; i++){
//             ind = gr->arestas[vert][i];
//             if(dist[ind] < 0){
//                dist[ind] = dist[vert] + 1;//ou peso da aresta
//                ant[ind] = vert;
//             }else{
//                 if(dist[ind] > dist[vert] + 1){
//                     dist[ind] = dist[vert] + 1;//ou peso da aresta
//                     ant[ind] = vert;
//                 }
//             }
//         }
//     }

//     free(visitado);
// }


// // http://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dfs1.html
// void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont){
//     int i;
//     visitado[ini] = cont;
//     for(i=0; i<gr->grau[ini]; i++){
//         if(!visitado[gr->arestas[ini][i]])
//             buscaProfundidade(gr,gr->arestas[ini][i],visitado,cont+1);
//     }
// }
// void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado){
//     int i, cont = 1;
//     for(i=0; i<gr->nro_vertices; i++)
//         visitado[i] = 0;
//     buscaProfundidade(gr,ini,visitado,cont);

//     for(i=0; i < gr->nro_vertices; i++)
//         printf("%d -> %d\n",i,visitado[i]);
// }
// // http://en.wikipedia.org/wiki/Breadth-first_search
// // http://www.princeton.edu/~achaney/tmve/wiki100k/docs/Breadth-first_search.html

// void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado){
//     int i, vert, NV, cont = 1;
//     int *fila, IF = 0, FF = 0;
//     for(i=0; i<gr->nro_vertices; i++)
//         visitado[i] = 0;

//     NV = gr->nro_vertices;
//     fila = (int*) malloc(NV * sizeof(int));
//     FF++;
//     fila[FF] = ini;
//     visitado[ini] = cont;
//     while(IF != FF){
//         IF = (IF + 1) % NV;
//         vert = fila[IF];
//         cont++;
//         for(i=0; i<gr->grau[vert]; i++){
//             if(!visitado[gr->arestas[vert][i]]){
//                 FF = (FF + 1) % NV;
//                 fila[FF] = gr->arestas[vert][i];
//                 visitado[gr->arestas[vert][i]] = cont;
//             }
//         }
//     }
//     free(fila);
//     for(i=0; i < gr->nro_vertices; i++)
//         printf("%d -> %d\n",i,visitado[i]);
// }

/* OUTRA VERS�O
void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado){
    int i, vert, NV, cont = 1;
    int *pilha, IP = 0, FP = 0;
    for(i=0; i<gr->nro_vertices; i++)
        visitado[i] = 0;

    NV = gr->nro_vertices;
    pilha = (int*) malloc(NV * sizeof(int));
    FP++;
    pilha[FP] = ini;
    while(IP != FP){
        IP = (IP + 1) % NV;
        vert = pilha[IP];
        if(!visitado[vert]){
            visitado[vert] = cont;
            cont++;
            for(i=0; i<gr->grau[vert]; i++){
                if(!visitado[gr->arestas[vert][i]]){
                    FP = (FP + 1) % NV;
                    pilha[FP] = gr->arestas[vert][i];
                }
            }
        }
    }
    free(pilha);
    for(i=0; i < gr->nro_vertices; i++)
        printf("%d -> %d\n",i,visitado[i]);
}
*/






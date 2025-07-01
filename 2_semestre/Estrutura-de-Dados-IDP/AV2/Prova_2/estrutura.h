#include <stdbool.h> 

// struct para representar um órgão
typedef struct orgao {
    int id;
    char tipo[20];
    char origem[50];
    char status[50];
    struct orgao* prox;
} Orgao;

// struct para pilha de alta prioridade
typedef struct pilha {
    Orgao* topo;
} Pilha;

// struct para fila de baixa prioridade
typedef struct fila {
    Orgao* inicio;
    Orgao* fim;
} Fila;

// struct para lista global de órgãos
typedef struct listaGlobal {
    Orgao* head;
} ListaGlobal;

//pilha
Pilha* cria_pilha();
void adiciona_pilha(Pilha* p, Orgao* o);
Orgao* remove_pilha(Pilha* p);
void exibe_pilha(Pilha* p);
void libera_pilha(Pilha* p);
bool pilha_vazia(Pilha* p); 

//fila
Fila* cria_fila();
void adiciona_fila(Fila* f, Orgao* o);
Orgao* remove_fila(Fila* f);
void exibe_fila(Fila* f);
void libera_fila(Fila* f);
bool fila_vazia(Fila* f); 

//lista global
ListaGlobal* cria_lista_global();
void adiciona_lista_global(ListaGlobal* lista, Orgao* o);
void atualiza_status_lista_global(ListaGlobal* lista, int id, const char* novo_status);
void exibe_lista_global(ListaGlobal* lista);
void libera_lista_global(ListaGlobal* lista);
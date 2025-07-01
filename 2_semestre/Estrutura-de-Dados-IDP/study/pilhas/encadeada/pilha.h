#define TAMANHO 5

// Definição do nó da pilha
typedef struct no {
    int valor;
    struct no* prox;
} No;

// Estrutura da pilha
typedef struct {
    No* topo;
    int tamanho;
} Pilha;

// Protótipos das funções
void inicializa_pilha(Pilha* p);
int push(Pilha* p, int valor);
int pop(Pilha* p, int* valor);
int peek(Pilha* p, int* valor);
int isEmpty(Pilha* p);
int isFull(Pilha* p);
void exibir(Pilha* p);  // Corrigido para aceitar Pilha*


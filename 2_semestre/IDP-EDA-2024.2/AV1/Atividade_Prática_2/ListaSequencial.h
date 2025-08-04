//Arquivo ListaSequencial.h
#define MAX 10
struct aluno {
    int codigo;
    char nome[30];
    float n1, n2, n3, n4;
    float np;
};

typedef struct lista Lista; // Define apelido (alias) para struct lista
Lista* cria_lista(); // prototipo da função para inicializar lista
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
void imprime_elemento(struct aluno al);
int insere_lista_vazia(Lista* li, struct aluno al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);

// QUESTAO 01 (Prototipo da funcao): inserir elementos na lista (ordenado pelo código)
int insere_lista_ordenada(Lista* li, struct aluno al);

// QUESTAO 02 (Prototipo da funcao): remover primeiro elemento da lista
int remove_lista_inicio(Lista* li);

// QUESTAO 03 (Prototipo da funcao): remover último elemento da lista
int remove_lista_final(Lista* li);

// QUESTAO 04 (Prototipo da funcao): remover elemento através do código
int remove_lista_pelo_codigo(Lista* li, int cod);

// QUESTAO 05 (Prototipo da funcao): consultar elemento pelo índice
int consulta_lista_pos(Lista* li, int ind);

// QUESTAO 06 (Prototipo da funcao): consultar elemento pelo código
int consulta_lista_cod(Lista* li, int cod);

//professor, criei uma função de sort para que a lista seja visualizada com os códigos organizados por ordem crescente
void ordena_lista(Lista* li);
//(usei um algorítimo de bubble sort)

float calcular_nota(float n1, float n2, float n3, float n4, float np);

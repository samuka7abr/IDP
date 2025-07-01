struct aluno {
    int matricula;
    char nome[50];
    float ap1, ap2, ap3, ap4;
    float np;
    float av; 
};

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento* Lista;
typedef struct elemento Elem;

//funções base
Lista* cria_lista();
void libera_lista(Lista* li);
int lista_vazia(Lista* li);
int tamanho_lista(Lista* li);
float calcular_nota(float ap1, float ap2, float ap3, float ap4, float np);
int insere_lista_inicio(Lista* li, struct aluno al);
void imprime_lista(Lista* li);

//funções das questões
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista_pelo_codigo(Lista* li, int cod);
int consulta_lista_cod(Lista* li, int cod);
int insere_melhores(Lista* li, struct aluno al);
int insere_piores(Lista* li, struct aluno al);
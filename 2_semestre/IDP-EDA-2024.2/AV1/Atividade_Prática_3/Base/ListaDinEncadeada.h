struct aluno {
    int codigo;
    char nome[50];
    float n1, n2, n3, n4;
    float np;
};

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento* Lista;
typedef struct elemento Elem;

//protótipo das funções base
Lista* cria_lista();
void libera_lista(Lista* li);
void imprime_lista(Lista* li);
int lista_vazia(Lista* li);
int tamanho_lista(Lista* li);
float calcular_nota(float n1, float n2, float n3, float n4, float np);
int insere_lista_inicio(Lista* li, struct aluno al);

//protótipo das funções das questões

//q1
int insere_lista_ordenada(Lista* li, struct aluno al); 
//q2
int remove_lista_inicio(Lista* li);                    
//q3
int remove_lista_final(Lista* li);                     
//q4
int remove_lista_pelo_codigo(Lista* li, int cod);      
//q5
int consulta_lista_cod(Lista* li, int cod);    


/*Atividade Prática 3: Criar função para
1. inserir elementos na lista (ordenado pelo 
código/matrícula)
2. remover primeiro elemento da lista
3. remover último elemento da lista
4. remover elemento através da 
código/matrícula
5. consultar elemento pela código/ 
matrícula
*/
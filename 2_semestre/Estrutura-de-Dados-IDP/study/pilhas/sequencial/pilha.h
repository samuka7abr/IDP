#define TAMANHO 5

typedef struct
{
    int top;
    int elem[TAMANHO];
} Stack;

void start_stack(Stack* s);
int push(Stack* s, int n); //"int n" states for the value included in the top of the stack
int pop(Stack* s, int* n);
int peek(Stack* s, int* n);
int isEmpty(Stack* s);
int isFull(Stack* s);
void show(Stack* s);



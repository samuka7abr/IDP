#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void start_stack(Stack* s) {
    s->top = -1;
}

int push(Stack* s, int n) {
    if (isFull(s)) return 0;
    s->top++;
    s->elem[s->top] = n;
    return 1;
}

int pop(Stack* s, int* n) {
    if (isEmpty(s)) return 0;
    *n = s->elem[s->top];  // Armazena o valor do top na variável
    s->top--;
    return 1;
}

int peek(Stack* s, int* n) {
    if (isEmpty(s)) return 0;
    *n = s->elem[s->top];  // Armazena o valor do top na variável
    return 1;
}

int isEmpty(Stack* s) {
    return (s->top == -1);
}

int isFull(Stack* s) {
    return (s->top == TAMANHO - 1);
}

void show(Stack* s) {
    if (isEmpty(s)) {
        printf("A pilha está vazia.\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->elem[i]);
    }
    printf("\n");
}

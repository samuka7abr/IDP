#include <stdio.h>
#include <stdint.h>

// declarações das funcoes implementadas em cod.s
size_t strlen(const char *s);
char *strcpy(char *dst, const char *src);
int strcmp(const char *a, const char *b);
int strncmp(const char *a, const char *b, size_t n);

int main(void) {
    char a[64] = "hello";
    char b[64] = " world";
    char c[64];

    printf("len(a) = %zu\n", strlen(a));

    strcpy(c, a);
    printf("c = %s\n", c);

    printf("strcmp(a, a) = %d\n", strcmp(a, a));
    printf("strcmp(a, b) = %d\n", strcmp(a, b));

    printf("strncmp(a, \"he\", 2) = %d\n", strncmp(a, "he", 2));
    printf("strncmp(a, \"hi\", 2) = %d\n", strncmp(a, "hi", 2));

    // strcat precisa de destino já com espaço
    char d[64] = "hello";
    extern char *strcat(char *dst, const char *src);
    strcat(d, b);
    printf("d = %s\n", d);

    return 0;
}


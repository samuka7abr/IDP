#include <bits/stdc++.h>
using namespace std;
/*função simples que verifica se o número passado
é primo ou não*/
bool ehPrimo(int p) {
    if (p < 2) return false;
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0)
            return false;
    }
    return true;
}
/*função que conta número de bits = a 1 num 
conjunto de bits*/
int contarBits(long long X) {
    int uns = 0; /*SEMPRE DECLARE VARIÁVEL
    QUE SERA INCREMENTADA COMO 0*/
    while (X) {
        uns += (X & 1); /*compara o primeiro bit
        com 1 e retorna o valor para ser 
        incrementado a 1*/
        X >>= 1; /*desloca o conjunto para a direita
        para descartar o bit que já foi comparado*/
    }
    return uns; /*retorna o número de uns*/
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    while (N--) {
        long long num;
        cin >> num;
        int bits = contarBits(num);
        if (ehPrimo(bits)) {
            cout << num << " eh um pribit\n";
        } else {
            cout << num << " nao eh um pribit\n";
        }
    }
    return 0;
}

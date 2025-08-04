#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while(T--){
        unsigned long long N;
        int P, Q;
        cin >> N >> P >> Q;

        /*atribui a posição de cada bit
        conforme o valor de Q e P*/
        int bitQ = (N >> P) & 1ULL;
        /*move os bits P ou Q posições
        para a direita e verifica se
        o valor do último bit é igual a 
        1 ou 0, atribuindo esse valor para a
        variável*/
        int bitP = (N >> Q) & 1ULL;

        /*se eles forem diferentes, efetua 
        a troca*/
        if(bitQ != bitP){
            /*cria uma mascara (p = 2) 0000 0100
            para poder fazer um OR entre as duas mascaras (p e q) e retornar 1 onde 
            os bits forem 1*/
            unsigned long long mask = (1ULL << P) | (1ULL << Q);
            /*então, faz um XOR em N para
            retornar 1 em bits diferentes*/
            N ^= mask;
        }

        cout << N << endl;
    }

    return 0;
}
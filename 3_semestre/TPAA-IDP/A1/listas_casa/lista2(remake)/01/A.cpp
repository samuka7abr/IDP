#include <bits/stdc++.h>
using namespace std;

int contarBits(long long x, long long y){
    /*SEMPRE DECLARAR OPS ENTRE "long long"
    COMO LONG LONG*/
    /*executa operação de XOR para
    retornar um valor em bits onde é 1
    apenas onde os bits de x e y forem diferentes*/
    long long resultado = x ^ y;
    int uns = 0;/*inicializa uma variável de 
    counter para registrar uns*/

    /*loop seria um true
    esperando um resultado em bits
    que contém apenas zeros*/ 
    while(resultado){
        /*executa uma operação de AND
        para comparar o bit da direita
        de cada número e verificar se ele 
        é igual a 1, atribuindo esse resultado
        à variável uns*/
        uns += resultado & 1;
        /*desloca os bits para direita 
        para descartar os bits que foram comparados
        na operação anterior*/
        resultado >>= 1;
    }
    /*retorna a variável uns já com os valores
    iterados*/
    return uns;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        long long X, Y;
        cin >> X >> Y;
        
        int res = contarBits(X, Y);
        cout << res << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); //otimiza o código
    cin.tie(nullptr); //otimiza o código

    int N;
    cin >> N;
    
    //declarando variáveis que serão comparadas mais tarde (soma total do array e a soma dos dados inseridos )
    long long somaTotal = (long long) N * (N + 1) / 2; //ao declarar uma expressão que precisa ser long long, usar (long long) antes dela
    long long somaDados = 0;

    //cria um loop para iterar até o tamanho da permutação (N - 1 pq tá faltando um número) 
    for(int i = 0; i < N - 1; i++){
        int num;
        cin >> num; //le um número a cada loop
        somaDados += num; //itera o valor do numero à variável somaDados
    }

    //printa isso tudo subtraindo a soma total da soma com um número faltante
    cout << somaTotal - somaDados << endl;

    return 0;
}
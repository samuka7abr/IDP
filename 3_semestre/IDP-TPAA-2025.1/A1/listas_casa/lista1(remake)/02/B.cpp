#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int D;
    //inicializa um loop que lê o valor de D e instancia uma condição de valor = a -1
    while(cin >> D && D != -1){
        string N; //declara uma string para armazenar o valor (mais fácil de percorrer)
        cin >> N;
        
        int sum  = 0; //inicializa a variável de soma (que será o número % 3)

        //soma os dígitos a "sum" e transforma cada um deles em int
        for(char c : N){
            //ao declarar uma string, transforme-a em inteiro subtraindo de '0'
            sum += c -'0';
        }
        //começa a saída
        cout << sum << " ";
        if(sum % 3 == 0){ //verifica se é divisível por 3
            cout << "sim";
        }else{
            cout << "nao";
        }
        cout << endl;
    }

    return 0;
}
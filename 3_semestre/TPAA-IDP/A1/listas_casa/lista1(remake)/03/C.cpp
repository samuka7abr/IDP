#include <bits/stdc++.h>
using namespace std;

string converteBase(long long num, int base){
    //caso a base seja 10, só converte o número para string
    if(base == 10) return to_string(num);
    //define caracteres para serem usados em base hexa
    string digitos = "0123456789ABCDEF";
    //inicia uma string de resultados vazia
    string resultado = "";

    //efetua a divisão enquanto o número for maior que zero
    while(num > 0){
        // define o resto, pegando o dígito menos significativo na base 
        int resto = num % base;
        //adiciona o caractere que corresponde ao início da string
        resultado = digitos[resto] + resultado;
        num /= base; //atualiza o número dividindo pela base
    }
    return resultado;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; //declara long long pq long long suporta ints de -2⁶³ a 2⁶³ - 1 
    int B;

    while(cin >> N >> B){ //enquanto a leitura de N e B não for = a -1 -1, continua
        if(N == -1 || B == -1) break;
        if(N == 0){ //se o número for zero, retorna zero
            cout << "0" << "\n";
            continue;
        }
        //chama a função para cada N e B de cada loop
        cout << converteBase(N, B) << endl;
    }

    return 0;
}
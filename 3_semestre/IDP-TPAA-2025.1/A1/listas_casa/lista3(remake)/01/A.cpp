#include <bits/stdc++.h>
using namespace std;

bool fechamento(string S){
    /*declara uma pilha de caracteres*/
    stack<char> pilha;

    /*em cpp, for...in se escreve:
    for a : b*/
    for(char ch : S){
        /*se o caractere for uma abertura de 
        expressão ( '({[' )
        ele dá push desse caractere na pilha*/
        if(ch == '(' || ch == '{' || ch == '['){
            pilha.push(ch);
            /*verifica se é de fechamento e, se a pilha
            estiver vazia, vai retornar falso, pois
            vai ser o primeiro caractere (sendo fechamento)
            da pilha*/
        }else if(ch == ')' || ch == '}' || ch == ']'){
            if(pilha.empty()){
                return false;
            }
            /*atribui uma variável com o topo
            da pilha*/
            char top = pilha.top();
            /*vai dando pop até a pilha chegar no seu
            início (a abertura)*/
            pilha.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    /*retorna true caso a pilha tenha sido esvaziada com sucesso*/
    return pilha.empty();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;

    if(fechamento(S)){
        cout << "OK" << endl;
    }else{
        cout << "SyntaxError" << endl; 
    }

    return 0;
}
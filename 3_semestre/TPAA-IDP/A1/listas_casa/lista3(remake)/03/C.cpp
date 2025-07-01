#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll soma = 0;
    ll media = 0;

    ll F, D;
    cin >> F >> D;

    /*declara um vetor de 30 posições*/
    vector<ll>subs(30);
    for(int i = 0; i < 30; i++){
        cin >> subs[i];
        soma += subs[i];
    }

    int index = 0; //armazena o primeiro valor do vetor

    for(int dia = 0; dia < D; dia++){
        media = (soma % 30 == 0) ? (soma / 30) : (soma / 30 + 1);
        /*a média é calculada assim:
        se existir qualquer resto 
        no em soma % 30, soma + 1*/
        F += media;

        /*descarta o valor mais antigo
        adicionando o novo valor dado pela 
        média*/
        soma = soma - subs[index] + media;
        subs[index] = media;
        index = (index + 1) % 30;
    }

    cout << F << endl;

    return 0;
}
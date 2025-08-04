#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, Q, nota;
    cin >> A >> Q;
    
    vector<ll> notas(A); /*declara um vetor do tipo ll (long long
    como declarado acima) de tamanho (A)*/
    for(int i = 0; i < A; i++){
        cin >> notas[i]; /*percorre esse vetor iterando
        a cada i, o valor inserido pelo cin*/
    }

    /*faz um sort para ordenar o vetor, passando os 
    parametros, inicio e fim*/
    sort(notas.begin(), notas.end());

    /*busca é a variável que vai ser usada
    para limitar a busca*/
    ll busca;
    for(int i = 0; i < Q; i++){ /*loop de casos*/
        cin >> busca;
        /*it é o valor retornado pelo upper_bound
        onde o primeiro valor maior que busca
        é retornado*/
        auto it = upper_bound(notas.begin(), notas.end(), busca);
        
        /*a função distance retorna a distancia entre o numero
        retornado por it e o fim do vetor notas*/
        ll dist = distance(it, notas.end());
        
        cout << dist << " notas maiores que " << busca << endl;
    }
    

    return 0;
}
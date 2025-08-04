#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Dado N disciplinas com certa quantidade de exercícios e H horas disponíveis,
// encontra o mínimo k (exercícios por sessão) tal que o total de sessões ≤ H.

ll sessoesNecessarias(const vector<long long> &exercicios, long long k){
    ll sessoes = 0;
    for(ll ex : exercicios){
        sessoes += (ex + k - 1) / k;
        // Para cada disciplina com ex exercícios,
        // precisamos de ceil(ex/k) sessões se cada sessão faz até k exercícios.
        // Em inteiro, ceil(ex/k) == (ex + k - 1) / k.
    }
    return sessoes;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    ll H;
    cin >> N >> H;

    vector<ll>exercicios(N);
    ll maxEx = 0;
    for(int i = 0; i < N; i++){
        cin >> exercicios[i];
        maxEx = max(exercicios[i], maxEx); /*
        pega o valor máximo entre
        exercicios[i] e maxEx, definindo
        a matéria com mais exercícios*/
    } 

    ll low = 1, high = maxEx, ans = high; /*low é um, high o maximo de exercicios
    em uma sessao, e ans é inicialmente definida como high*/
    while(low <= high){ /*enquanto low não chegar ao valor de high*/
        ll mid = (low + high) / 2; /*calcula o meio*/
        ll totalSessoes = sessoesNecessarias(exercicios, mid); //calcula total funções pela func
        if(totalSessoes <= H){/*
            se o valor total de sessões
            for menor ou igual ao total
            de horas, a resposta vira o 
            meio, pois chegou ao valor equilibrado*/
            ans = mid;
            /*define high como 1 elemento
            abaixo de mid*/
            high = mid - 1;
        }else{
            /*se não, continua aumentando low
            até o tamnho de high*/
            low = mid + 1;
        }

    }

    cout << ans << endl;

    return 0;
}
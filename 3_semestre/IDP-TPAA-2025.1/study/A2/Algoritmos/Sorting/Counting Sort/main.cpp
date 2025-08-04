#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void countingSort(vector<int>& tab) {
    //encontra o maior valor dentro do vetor tav para dimensionar tab
    //(max() não funciona pq não trabalha com grandes espaços, só dois valores)
    int maxVal = *max_element(tab.begin(), tab.end()); 
    //como índices vão de 0 a N, declara maxVal + 1 para contar até a última posição
    //o segundo parametro inicializa os elementos do vetor como 0
    vector<int> count(maxVal + 1, 0);

    //conta quantas vezes cada valor aparece em tab
    for (int v : tab){ 
        count[v]++;
    }

    //declara um index para manipular o vetor original (tab)
    int idx = 0;
    //Para cada valor i, escreve i em tab count[i] vezes
    for (int i = 0; i <= maxVal; i++) {
        //decrementa o count[i] (posição iterada do vetor)
        while (count[i]-- > 0) {
            //// Escreve uma ocorrência de i em tab e avança idx
            tab[idx++] = i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int>tab(N);
    for(int i = 0; i < tab.size(); i++){
        cin >> tab[i];
    }

    cout << "vetor antes da ordenação" << endl;

    for(int j = 0; j < tab.size(); j++){
        cout << tab[j] << " ";
    }

    cout << endl;

    countingSort(tab);
    cout << "vetor depois da ordenação:" << endl;

    for(int j = 0; j < tab.size(); j++){
        cout << tab[j] << " " ;
    }
    cout << endl;
    return 0;
}
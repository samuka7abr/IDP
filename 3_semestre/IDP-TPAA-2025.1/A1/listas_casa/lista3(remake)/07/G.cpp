#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    // Leitura da matriz e da primeira coluna
    vector<vector<int>> valores(N, vector<int>(M));
    vector<int> primeiraColuna(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> valores[i][j];
            if(j == 0)
                primeiraColuna[i] = valores[i][j];
        }
    }

    // Para cada consulta V, fazemos:
    // 1) achar, em primeiraColuna (ordenada), a primeira linha cujo
    //    valor inicial > V, então retrocedemos uma linha
    // 2) verificamos se nessa linha o último elemento >= V
    // 3) se sim, buscamos em tempo logarítmico nessa linha via lower_bound
    //    e conferimos igualdade
    while(Q--){
        int V;
        cin >> V;

        // encontra primeira linha com primeiraColuna > V
        auto it = upper_bound(primeiraColuna.begin(), primeiraColuna.end(), V);
        if(it == primeiraColuna.begin()){
            cout << "-1 -1\n";
            continue;
        }
        int linha = int(it - primeiraColuna.begin()) - 1;  // 0‑based

        // se o maior elemento dessa linha for menor que V, não tem
        if(valores[linha][M-1] < V){
            cout << "-1 -1\n";
            continue;
        }

        // busca binária nessa linha
        auto jt = lower_bound(valores[linha].begin(), valores[linha].end(), V);
        if(jt != valores[linha].end() && *jt == V){
            int col = int(jt - valores[linha].begin());  // 0‑based
            cout << linha << " " << col << "\n";
        } else {
            cout << "-1 -1\n";
        }
    }

    return 0;
}

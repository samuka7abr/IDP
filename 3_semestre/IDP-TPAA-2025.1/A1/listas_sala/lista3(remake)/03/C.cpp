#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    queue<int> cartas;
    for(int i = N; i >= 1; i--){
        cartas.push(i);
    }

    vector<int> descartadas;
    while(cartas.size() > 1){
        /*descarta a primeira carta e junta
        ao monte de cartas descartadas*/
        descartadas.push_back(cartas.front());
        cartas.pop();

        /*agora, com a primeira carta descartada,
        move a nova primeira carta para o fim do
        baralho (pop push)*/
        int carta = cartas.front();
        cartas.pop();
        cartas.push(carta);
    }

    cout << "Descarte: "; 
    if(!descartadas.empty()){
        cout << descartadas[0];
        for (size_t i = 1; i < descartadas.size(); i++){
            cout << ", " << descartadas[i];
        }
    }
    cout << "\n";

    cout << "Ultima carta: " << cartas.front() << "\n";

    return 0;
}
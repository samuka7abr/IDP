#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Pokemon{
    string nome;
    int forca;
    int tempo;
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int P;
    cin >> P;

    int timer = 0;
    auto compare = [](Pokemon const &a, Pokemon const &b){
        if(a.forca != b.forca){
            return a.forca < b.forca;
        }

        return a.nome < b.nome;
    };

    priority_queue<Pokemon, vector<Pokemon>, decltype(compare)> Pokedex(compare);

    for(int i = 0; i < P; i++){
        Pokemon x;
        cin >> x.nome >> x.forca;
        x.tempo = timer++;
        Pokedex.push(x);
    }

    while(Pokedex.size() > 1){
        auto PrimeiroForte = Pokedex.top(); 
        Pokedex.pop();
        auto SegundoForte = Pokedex.top();
        Pokedex.pop();

        cout << PrimeiroForte.nome << " ("  << PrimeiroForte.forca << ")" << " x " << "(" << SegundoForte.forca << ") " << SegundoForte.nome;

        cout << " : " ;

        if(PrimeiroForte.forca > SegundoForte.forca){
            cout << PrimeiroForte.nome << " venceu\n";
            PrimeiroForte.forca -= SegundoForte.forca;
            PrimeiroForte.tempo = timer++;

            if(PrimeiroForte.forca > 0){
                Pokedex.push(PrimeiroForte);
            }
        }else if(PrimeiroForte.forca < SegundoForte.forca){
            cout << SegundoForte.nome << " venceu\n";
            SegundoForte.forca -= PrimeiroForte.forca;
            SegundoForte.tempo = timer ++;

            if(SegundoForte.forca > 0){
                Pokedex.push(SegundoForte);
            }
        }else{
            cout << "empate\n";
        }
    }

    if(Pokedex.empty()){
        cout << "nenhum vencedor" << endl;
    }else{
        auto vencedor = Pokedex.top();
        cout << vencedor.nome << " venceu com " << vencedor.forca << endl;
    }

    return 0;
}
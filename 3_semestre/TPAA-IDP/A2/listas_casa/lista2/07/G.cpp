#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Digimon{
    string nome;
    int fome;
    int chegada;  
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A;
    cin >> A;

    auto compare = [](Digimon const &a, Digimon const &b) {
        if (a.fome != b.fome) return a.fome > b.fome;
        return a.chegada < b.chegada;
    };

    set<Digimon, decltype(compare)> fila(compare);
    unordered_map<string, decltype(fila.begin())> mp;
    vector<string> servidos;

    int timer = 0;

    while (A--){
        string op;
        cin >> op;

        if (op == "CHEGA"){
            Digimon d;
            cin >> d.nome >> d.fome;
            d.chegada = timer++;
            auto it = fila.insert(d).first;
            mp[d.nome] = it;
        }
        else if (op == "FOME"){
            string nome; int x;
            cin >> nome >> x;
            auto it = mp[nome];
            Digimon d = *it;
            fila.erase(it);
            d.fome += x;
            it = fila.insert(d).first;
            mp[nome] = it;
        }
        else if (op == "SAI"){
            string nome;
            cin >> nome;
            auto it = mp[nome];
            fila.erase(it);
            mp.erase(nome);
        }
        else { 
            auto it = fila.begin();
            servidos.push_back(it->nome);
            mp.erase(it->nome);
            fila.erase(it);
        }
    }

    for (auto &nome : servidos)
        cout << nome << "\n";

    return 0;
}

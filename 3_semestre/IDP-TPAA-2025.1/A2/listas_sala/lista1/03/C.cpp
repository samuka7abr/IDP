#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int P, S;
    cin >> P >> S;

    map<string, set<string>> escolha;

    while(P--){
        string name, c1, c2, c3;
        cin >> name >> c1 >> c2 >> c3;
        escolha[name] = {c1, c2, c3};
    }

    while(S--){
        string name, pegou;
        cin >> name >> pegou;

        auto it = escolha.find(name);
        if(it == escolha.end()){
            cout << name << " queria ganhar qualquer coisa e ganhou " << pegou << "!\n";
        }else if(it->second.count(pegou)){
            cout << name << " conseguiu ganhar " << pegou << "!\n";
        }else{
            cout << name << " infelizmente ganhou " << pegou << "...\n";
        }
    }

    return 0;
}

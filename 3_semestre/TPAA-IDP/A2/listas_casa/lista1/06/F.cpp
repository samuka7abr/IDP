#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    
    
    while(N--){
        int qtd;
        cin >> qtd;
        map<pair<int, string>, bool> mp;

        int erros = 0;
        
        while(qtd--){
            int matricula;
            string materia;
            cin >> matricula >> materia;
            auto chave = make_pair(matricula, materia);
            if(mp.count(chave) == 0){
                mp.emplace(chave, true);
            }else{
                erros++;
                
            }
        }

        if(erros != 0){
            cout << "Corrompido com " << erros << " erro(s)\n"; 
        }else{
            cout <<"Arquivo OK\n";
        }
    }

    return 0;
}

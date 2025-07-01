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
        string repetidas = "";
        string baralho1, baralho2;
        cin >> baralho1 >> baralho2;
        
        set<char> S;
        for(char c : baralho1){
            S.insert(c);
        }

        set<char> visto; 
        for(char c : baralho2){
            if(S.count(c) && !visto.count(c)){
                repetidas += c;
                visto.insert(c);
            }
        }
        
        sort(repetidas.begin(), repetidas.end());
        if(!repetidas.empty()){ 
            cout << repetidas << endl;
        }else{
            cout << "Baralhos prontos para o duelo\n";
        }
    }


    return 0;
}

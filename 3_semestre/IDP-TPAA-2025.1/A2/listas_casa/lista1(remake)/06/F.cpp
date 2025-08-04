#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18; 

int main(){
    otim;
    int N;
    cin >> N;
    
    while(N--){
        int M;
        cin >> M;
        
        map<pair<int, string>, bool> mp;
        
        int erros = 0;

        for(int i = 0; i < M; i++){
            int ra;
            string materia;
            cin >> ra >> materia;

            auto chave = make_pair(ra, materia);

            if(mp.count(chave)){
                erros ++;
            }else{
                mp.emplace(chave, true);
            }
        }
        if(erros == 0){
            cout << "Arquivo OK" << endl;
        }else{
            cout << "Corrompido com " << erros <<  " erro(s)" << endl;
        }
    }

    return 0;
}

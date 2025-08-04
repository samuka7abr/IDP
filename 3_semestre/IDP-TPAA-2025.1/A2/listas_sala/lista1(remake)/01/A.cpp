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
    int N, M;
    cin >> N;

    vector<int> arvore(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arvore[i];
    }
    
    cin >> M;
    
    while(M--){
        int p;
        cin >> p;

        int pai = p / 2;
        int dir = p * 2 + 1;
        int esq = p * 2;

        if(arvore.size() == 2){
            cout << "NULL" << endl;
            break;
        }
        
        if(p == 1){
            cout << "RAIZ - " ;
        }else{
            cout << arvore[pai] << " - ";
        }

        if(esq > N || arvore[esq] == -1){
            cout << "NULL";
        }else{
            cout << arvore[esq];
        }

        cout << " ";

        if(dir > N || arvore[dir] == -1){
            cout << "NULL" << endl;
        }else{
            cout << arvore[dir] << endl;
        }
    }

    return 0;
}

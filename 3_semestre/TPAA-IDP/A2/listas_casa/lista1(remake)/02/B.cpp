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

/*
nesse tipo de questão, implemente árvores 
utilizando vetores.
lembre-se sempre de manter a primeira[0] posição inutilizada
pois a arvore não funciona caso utilize

utilizando vetores, os filhos são:
direita: 2 * p + 1
esquerda: p * 2
*/
int main(){
    otim;
    int N, M;
    cin >> N >> M;
    vector<int> arvore(N);
    for(int i = 1; i <= N; i++){
        cin >> arvore[i];
    }

    while(M--){
        int p;
        cin >> p;
        
        if(N == 1){
            cout << "NULL" << endl;
            break;
        }

        int dir = 2 * p + 1;
        int esq = 2 * p;

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

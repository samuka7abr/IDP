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
    cin >> N >> M;

    vector<int> arvore(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arvore[i];
    }

    while(M--){
        int p;
        cin >> p;

        int pai = p / 2;

        if(arvore.size() == 2){
            cout << "NULL" << endl;
            break;
        }

        if(p == 1){
            cout << "RAIZ" << endl;
            continue;
        }

        if(arvore[pai] == -1){
            cout << "NULL" << endl;
        }else{
            cout << arvore[pai] << endl;
        }
    }

    return 0;
}

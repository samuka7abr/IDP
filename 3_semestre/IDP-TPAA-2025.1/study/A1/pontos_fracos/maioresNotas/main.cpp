#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A;
    int Q;
    cin >> A >> Q;

    vector<ll>notas(A);
    for(int i = 0; i < A; i++){
        cin >> notas[i];
    }

    int busca;
    while(Q--){ 
        cin >> busca;
        
        auto it = upper_bound(notas.begin(), notas.end(), busca);

        ll result = notas.end() - it;

        cout << result << " notas maiores que " << busca << endl;
    }


    return 0;
}
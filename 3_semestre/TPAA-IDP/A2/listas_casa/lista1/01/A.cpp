#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A;
    scanf("%lld", &A);
 
    vector<ll>notas(A);
    for(ll i = 0; i < A; i++){
        scanf("%lld", &notas[i]);
    }
    sort(notas.begin(), notas.end());
   
    for(ll i = 0; i < A; i++){
        printf("%d\n", notas[i]);
    }
 
    return 0;
}
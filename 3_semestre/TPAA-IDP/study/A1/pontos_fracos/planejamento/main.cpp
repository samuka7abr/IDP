#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sessoesNec(const vector<ll> &exercicios, ll x){
    ll total = 0;
    for(ll ex : exercicios){
        total += (ex + x - 1) / x;  
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll N, H;
    cin >> N >> H;

    ll maxEx = 0;
    vector<ll>exercicios(N);
    for(int i = 0; i < N; i++){
        cin >> exercicios[i];
        maxEx = max(exercicios[i], maxEx);
    }

    ll low = 1, high = maxEx, mid, res;
    while(low <= high){
        mid = (low + high) / 2;
        ll totalSessoes = sessoesNec(exercicios, mid);
        if(totalSessoes <= H){
            res = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }

    }

    cout << res << endl;

    return 0;
}
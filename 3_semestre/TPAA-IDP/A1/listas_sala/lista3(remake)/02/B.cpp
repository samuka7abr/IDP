#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, B, C;
    cin >> A >> B >> C;
    
    double lo = 0.0, hi = 1e9, mid;
    double tol = 1e-9;

    while (hi - lo > tol){
        mid = (hi + lo) / 2;
        double valor = A * mid + B * sin (mid);
        if(valor < C){
            lo= mid;
        }else{
            hi = mid;
        }
    }

    cout << fixed << setprecision(4) << hi << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int contarBits(long long x, long long y) {
    long long resultado = x ^ y;
    int uns = 0;
    while (resultado) {
        uns += resultado & 1;
        resultado >>= 1;
    }
    return uns;
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        long long x, y;
        cin >> x >> y;
        
        int dif = contarBits(x, y);

        cout << dif << endl;

    }

    return 0;
}
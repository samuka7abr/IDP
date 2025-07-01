#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    for(int i = 0; i < T ; i++){
        unsigned long long N;
        int P, Q;
        cin >> N >> P >> Q;

        int bitP = (N >> P) & 1ULL;
        int bitQ = (N >> Q) & 1ULL;
        
        if(bitP != bitQ){
            unsigned long long mascara = (1ULL << P) | (1ULL << Q);
            N ^= mascara;  
        }
        
        cout << N << endl;

    }

    return 0;
}
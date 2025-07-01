#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long N;
    int Q;
    cin >> N >> Q;

    for(int i = 0; i < Q; i++){
        int V;
        cin >> V;
        
        bool acesa = ((N >> V) & 1ULL) == 1ULL;

        cout << (acesa ? "acesa\n" : "apagada\n");
    }


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int N, B;
    cin >> N >> B;

    unsigned int mask = ~(1u << B);

    for(int i = 0; i < N; i++){
        unsigned int V;
        cin >> V;

        cout << (V & mask) << endl;
    }
    return 0;
}
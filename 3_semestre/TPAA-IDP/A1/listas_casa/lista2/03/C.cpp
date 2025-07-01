#include <bits/stdc++.h> 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    
    int N; 
    int B;
    cin >> N >> B;

    for(int i = N ; i > 0 ; i--){
        int V;
        cin >> V;
        
        int R = V | (1 << B);

        cout << R << endl;

    }
    return 0;
}
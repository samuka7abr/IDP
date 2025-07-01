#include <bits/stdc++.h>
using namespace std;

int M(int N){
    if(N > 100){
        return N - 10;
    }else{
        return M(M(N + 11));
    }
}

int main(){
    int C;
    cin >> C;

    for(int i =0 ; i < C; i++){
        int N;
        cin >> N;
        cout << M(N) << endl;
    }
    return 0;
}
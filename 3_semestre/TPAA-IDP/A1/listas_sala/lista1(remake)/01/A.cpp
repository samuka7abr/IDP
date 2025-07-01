#include <bits/stdc++.h>
using namespace std;
//essa forma resolve de forma não-recursiva, só verificando o valor de N segundo a função
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> C;

    while(C--){
        int N;
        cin >> N;
        if(N <= 100){
            cout << 91 << "\n";
        }else{
            cout << N - 10 << "\n";
        }
    }

    return 0;
}

//também existe a função recursiva:

#include <bits/stdc++.h>
using namespace std;

//declara a função e usa ela dentro de ela mesma para casos n > 100
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
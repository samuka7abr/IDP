#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        long long A, B, Y;
        cin >> A >> B >> Y;

        /*já que o XOR retorna 1 quando os bits são diferentes, 
        basta executar XOR entre as 3 variáveis*/
        long long C = A ^ B ^ Y;

        /*verifica conforme o número
        dado pelo problema*/ 
        if(C <= 100000000){
            cout << C << endl;
        }else{
            cout << -1 << endl;
        }


    }   
    return 0;
}
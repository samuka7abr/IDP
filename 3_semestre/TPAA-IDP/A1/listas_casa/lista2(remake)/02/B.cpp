#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    /*decrementa T até a execução 
    do programa parar*/
    while(T--){
        long long A, B, C, D, Y;
        cin >> A >> B;
        cin >> Y;

        /*executa uma operação OR
        que retorna bits 1 pelo menos quando 
        1 dos bits é 1 para gerar bits que serão
        juntados à variável C para gerar Y*/
        D = A | B;

        /*inverte os bits de Y para verificar se 
        a comparação com D não resulta em zero (bits
        se anulam)*/
        if(D & (~Y)){
            cout << -1 << endl;
            /*caso sim, esse número não existe.
            então, retorna -1*/
        }else{
            C = Y ^ D;
            cout << C << endl;
        }
    }

    return 0;
}
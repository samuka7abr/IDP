#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /*inicia o loop para poder usar o -1 como 
    condição de break*/
    while(true){
        int N;
        cin >> N;

        if(N == -1) break;  

        //inicializa o solitário como zero
        //bits zerados

        int solitario = 0;
        for(int i = 0; i < N; i++){
            int num;
            cin >> num; //le o numero a cara it


            //realiza uma operação de XOR
            //XOR com num: pares x^x = 0, 0^x = x
            /*
                como cada xor zera se os 
                números forem iguais,
                apenas o número sem par vai 
                permanecer com seus bits 
                armazenados ao final do loop
            */
            solitario ^= num;
        }
        cout << solitario << endl;
    }

    return 0;
}
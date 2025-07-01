#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, B;
    cin >> N >> B;

    /*cria uma mascara de bits que será comparada
    com num dentro do nosso loop.
    essa mascara consiste em:
    criar um número em binário (B = 3)
    0000 1000 que será comparado com um
    OR com nosso num para reativar o bit
    caso ele esteja desativado (0)*/
    int mascara = 1 << B;
    while(N--){
        int num;
        cin >> num;
        cout << (num | mascara) << endl;
    }

    return 0;
}
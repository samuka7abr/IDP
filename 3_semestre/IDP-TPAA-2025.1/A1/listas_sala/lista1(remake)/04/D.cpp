#include <bits/stdc++.h>
using namespace std;
//função para verificação de primos mais completa
//conta casos como 2, pares e negativos
bool ehPrimo(int n) {
    if (n < 2) return false;         
    if (n == 2) return true;       
    if (n % 2 == 0) return false;    
    for (int i = 3; i * i <= n; i += 2) { 
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N; 

    while (N--) {
        int V;
        cin >> V; 
        /*verifica se o número primo é gemeo
        garantindo que num + 2 ou num - 2 também é
        primo*/
        if (ehPrimo(V) && (ehPrimo(V - 2) || ehPrimo(V + 2)))
            cout << "O numero " << V << " eh um primo gemeo" << "\n";
        else
            cout << "O numero " << V << " nao eh um primo gemeo" << "\n";
    }
    
    return 0;
}

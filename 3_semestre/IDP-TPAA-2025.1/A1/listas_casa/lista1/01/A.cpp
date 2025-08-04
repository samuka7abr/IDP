#include <iostream>
using namespace std;

int main() {
    
    int N;
    cin >> N;
    
    long long somaTotal = (long long) N * (N + 1) / 2;
    long long somaDados = 0;
    
    for (int i = 0; i < N - 1; i++) {
        int numero;
        cin >> numero;
        somaDados += numero;
    }
    
    cout << somaTotal - somaDados << "\n";
    
    return 0;
}

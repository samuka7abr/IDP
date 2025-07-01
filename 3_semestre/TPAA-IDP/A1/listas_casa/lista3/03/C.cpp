#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long F; 
    int D;
    cin >> F >> D;

    vector<long long> janela(30);
    long long somaJanela = 0;

    for (int i = 0; i < 30; i++) {
        cin >> janela[i];
        somaJanela += janela[i];
    }

    int index = 0;

    for (int dia = 0; dia < D; dia++) {
        long long media = (somaJanela % 30 == 0) ? (somaJanela / 30) : (somaJanela / 30 + 1);
        F += media;

        somaJanela = somaJanela - janela[index] + media;
        janela[index] = media;
        index = (index + 1) % 30;
    }

    cout << F << "\n";

    return 0;
}

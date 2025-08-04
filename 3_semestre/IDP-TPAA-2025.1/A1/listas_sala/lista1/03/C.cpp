#include <iostream>
using namespace std;

int main() {
    unsigned long long painel;
    int Q;
    
    cin >> painel >> Q;
    
    for (int i = 0; i < Q; i++) {
        int C;
        cin >> C;
        if (painel & (1ULL << C))
            cout << "acesa" << "\n";
        else
            cout << "apagada" << "\n";
    }
    
    return 0;
}

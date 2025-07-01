#include <iostream> 
#include <cmath>
using namespace std;

bool ehPrimo(int p) {
    if (p < 2) return false;

    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    int i = 0, p;
    while(i < n){
        cin >> p;
        if(ehPrimo(p)){
            cout << "o numero " << p << " eh primo" << endl;  
        }else{
            cout << "o numero " << p << " nao eh primo" << endl;
        }
        i++;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

bool ehPrimo(int p){
    if(p < 2) return false;

    for(int i = 2; i <= sqrt(p); i++){
        if(p % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    while(N--){
        int num;
        cin >> num;

        if(ehPrimo(num)){
            cout << "o numero " << num << " eh primo" << endl;
        }else{
            cout << "o numero " << num << " nao eh primo" << endl;
        }
    }
    
    return 0;
}
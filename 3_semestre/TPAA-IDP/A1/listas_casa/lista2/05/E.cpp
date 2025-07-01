#include <bits/stdc++.h>
#define LOOP(N) for(int i = 0; i < (N); i++)
using namespace std;

bool ehPrimo(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;

    LOOP(N){
        long long num;
        cin >> num;
        
        long long temp = num; 
        int count = 0;
        while(temp){
            count += (temp & 1);
            temp >>= 1;
        }

        if(ehPrimo(count)){
            cout << num << " eh um pribit" << endl;
        } else {
            cout << num << " nao eh um pribit" << endl;
        }
    }

    return 0;
}

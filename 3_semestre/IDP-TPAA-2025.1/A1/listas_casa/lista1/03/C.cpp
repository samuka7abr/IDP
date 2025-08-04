#include <iostream>
#include <string>
using namespace std;

int main(){
    long long N;
    int B;
    while(cin >> N >> B){
        if(N == -1 && B == -1)
            break;
        if(N == 0){
            cout << "0" << "\n";
            continue;
        }
        string resultado = "";
        long long num = N;
        while(num > 0){
            int rem = num % B;
            num /= B;
            char digit = (rem < 10) ? '0' + rem : 'A' + (rem - 10);
            resultado.push_back(digit);
        }
        int len = resultado.size();
        for(int i = 0; i < len / 2; i++){
            char tmp = resultado[i];
            resultado[i] = resultado[len - 1 - i];
            resultado[len - 1 - i] = tmp;
        }
        cout << resultado << "\n";
    }
    return 0;
}

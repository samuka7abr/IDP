#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        long long A, B;
        long long Y;
        cin >> A >> B;
        cin >> Y;

        long long C = A ^ B ^ Y;

        if(C <= 100000000){
            cout << C << endl;
        }else{
            cout << -1 << endl;
        }
    }

    return 0;
}
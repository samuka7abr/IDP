#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while(T--){
        string R, S;
        cin >> R >> S;
        string resultado ;

        for(size_t i = 0; i < R.size(); i++){
            if(R[i] == S[i]){
                resultado += toupper(R[i]); 
            }else{
                resultado += tolower(R[i]);
            }
        }

        cout << resultado << endl;

    }

    return 0;
}
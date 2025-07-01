#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        string R, S;
        cin >> R >> S;
        string result ;

        for(size_t i = 0; i < R.size(); i++){
            if(R[i] == S[i]){
                result += toupper(R[i]);
            }else{
                result += tolower(R[i]);
            }
        }
        cout << result << endl;
    }

    return 0;
}
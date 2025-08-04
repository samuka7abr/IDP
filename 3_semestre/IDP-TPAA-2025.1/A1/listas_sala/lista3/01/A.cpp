#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        string B;
        cin >> B;

        int abertos = 0;
        int pedras = 0;

        for(char j : B){
            if(j == '<'){
                abertos++;
            }else if(j == '>' && abertos != 0){
                abertos--;
                pedras++;
            }
        }
        cout << pedras << endl;
    }

    return 0;
}
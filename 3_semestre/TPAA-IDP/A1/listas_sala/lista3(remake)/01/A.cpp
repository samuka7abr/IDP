#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    
    
    for(int i = 0; i < N; i++){
        string B;
        cin >> B;

        int pedras = 0;
        int abertos = 0;

        for(char ch : B){
            if(ch == '<'){
                abertos++;
            }else if(ch == '>' && abertos != 0){
                abertos --;
                pedras ++;
            }
        }

        cout << pedras << endl;
    }


    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, C;
    cin >> N >> C;
    vector<int> arvore(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arvore[i];
    }
 
    while(C --){
        int num;
        cin >> num;
        if(arvore.size() == 2){
            cout << "NULL" << endl;
            break;
        }
        int pai = num / 2;
        if(pai < 1){
            cout << "RAIZ" << endl;
        }else{
            cout << arvore[pai] << endl;
        }
    }
 
 
    return 0;
}
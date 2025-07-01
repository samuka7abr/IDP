#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, C;
    cin >> N >> C;

    vector<int>arvore(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arvore[i];
    }

    while(C--){
        int num;
        cin >> num;

        if(arvore.size() == 2){
            cout << "NULL" << endl;
            break;
        }

        int L = num * 2;
        int R = num * 2 + 1;

        if (L <= N && arvore[L] != -1) 
            cout << arvore[L];
        else 
            cout << "NULL";

        cout << ' ';

        if (R <= N && arvore[R] != -1) 
            cout << arvore[R];
        else 
            cout << "NULL";

        cout << endl;
    }
    return 0;
}

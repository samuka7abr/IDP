#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    set<string> S;

    while(N--){
        int qtd;
        cin >> qtd;
        while(qtd--){
            string item;
            cin >> item;
            if(S.count(item) == 0){
                S.insert(item);
                cout << "adicionando " << item << "\n";
            }else{
                cout << item << " ja tem\n"; 
            }
        }
    }

    cout << "Itens do churrasco:" << endl;
    for(string s : S){
        cout << s << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string nome;
    int crime;

    unordered_map<string,int> database;

    while(cin >> nome >> crime){
        if(nome == "fim" && crime == 0){
            break;
        }
        int &cnt = database[nome]; 

        if (cnt == 0) {
            cout << nome << " eh reu primario\n";
        } else {
            cout << nome << " eh reincidente com " << (cnt) << " crime(s)\n";
        }
        cnt++; 
    }

    return 0;
}

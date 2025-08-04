#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18; 

int main(){
    otim;
    int N;
    cin >> N;

    while(N--){
        set<char> visto;
        set<char> repetido;

        string b1, b2;
        cin >> b1 >> b2;

        for(char c : b1){
            visto.insert(c);
        }
        
        for(char c : b2){
            if(visto.count(c)){
                repetido.insert(c);
            }
        }
        
        if(repetido.empty()){
            cout << "Baralhos prontos para o duelo" << endl;
        }else{
            for(auto c : repetido){
                cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}

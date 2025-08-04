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
    string nome;
    int crime;

    unordered_map <string, int> dados;

    while(true){
        cin >> nome >> crime;

        if(nome == "fim") break;

        int &cnt = dados[nome];

        if(cnt == 0){
            cout << nome << " eh reu primario" << endl;
        }else{
            cout << nome << " eh reincidente com " << cnt << " crime(s)" << endl;
        }

        cnt ++;
    }
    return 0;
}

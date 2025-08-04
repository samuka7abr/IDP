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
    int N, M;
    cin >> N >> M;

    map<string, set<string>> map;

    while(N--){
        string name, c1, c2, c3;
        cin >> name >> c1 >> c2 >> c3;

        map[name] = {c1, c2, c3};
    }

    while(M--){
        string nome, ganhou;
        cin >> nome >> ganhou;

        auto it = map.find(nome);

        if(it == map.end()){
            cout << nome << " queria ganhar qualquer coisa e ganhou " << ganhou << "!\n";
        }else if(it->second.count(ganhou)){
            cout << nome << " conseguiu ganhar " << ganhou << "!\n"; 
        }else{
            cout << nome << " infelizmente ganhou " << ganhou << "...\n";
        }
    }
    
    return 0;
}

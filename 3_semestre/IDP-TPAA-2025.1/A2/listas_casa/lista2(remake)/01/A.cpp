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
        multiset<char> ms;
        set<char> s;

        string pedra, neg;
        cin >> pedra >> neg;

        for(char c : pedra){
            ms.insert(c);
        }

        int qtd = 0;

        for(char ch: neg){
            auto r = s.insert(ch);
            if(r.second){
                qtd += ms.count(ch);
            }
        }
        
        cout << "Contem " << qtd << " pedras negociaveis" << endl;   
    }
    return 0;
}

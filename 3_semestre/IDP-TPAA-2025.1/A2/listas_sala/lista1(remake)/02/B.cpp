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
        set<char> s;
        
        string word;
        cin >> word;
        
        bool ok = true;
        for(char c : word){
            if(s.count(c)){
                ok = false;
            }else{
                s.insert(c);
            }
        }

        if(ok){
            cout << "STRONGRAMA" << endl;
        }else{
            cout << "WEAKORD" << endl;
        }
    }
    
    return 0;
}

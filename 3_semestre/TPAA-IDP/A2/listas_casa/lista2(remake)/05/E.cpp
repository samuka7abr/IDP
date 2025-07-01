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
        string R, S;
        cin >> R >> S;

        if(R.size() != S.size()){
            cout << "DIFERENTES" << endl;
            continue;
        }

        unordered_map<char, int> um;
        um.reserve(R.size());

        for(char c : R){
            um[c]++;
        }

        bool ok = true;
        for(char c : S){
            auto it = um.find(c);
            if(it == um.end() || --it->second < 0){
                ok = false;
                break;
            }
        }
        if(ok){
        cout << "ANAGRAMAS" << endl;
        }else{
            cout << "DIFERENTES" << endl;
        }
    }

    
    return 0;
}

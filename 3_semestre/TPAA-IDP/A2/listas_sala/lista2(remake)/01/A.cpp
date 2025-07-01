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
    string S;
    cin >> S;
    set<char> s;

    for(char c : S){
        s.insert(c);
    }

    for(char c : s){
        cout << c;
    }
    
    cout << endl;
    return 0;
}

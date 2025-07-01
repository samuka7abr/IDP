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
    int M, C;
    cin >> M >> C;

    vector<vector<int>> v(M);
    
    int num;
    for(int i = 0; i < C; i++){
        cin >> num;
        int idx = num % M;
        v[idx].pb(num);
    }

    for(int i = 0; i < M; i++){
        cout << i << " -> ";
        
        for(int j : v[i]){
            cout << j << " -> ";
        }

        cout << "\\" << endl;
    }

    return 0;
}

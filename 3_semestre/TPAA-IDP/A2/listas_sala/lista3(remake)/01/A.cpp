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

vector<vector<int>> mat;
int n, m;

int main(){
    otim;
    cin >> n >> m;
    mat.assign(n + 1, vector<int>(n + 1, 0));

    while(m--){
        int u, v;
        cin >> u >> v;

        mat[u][v] = mat[v][u] = 1;
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << mat[i][j] << (j < n ? ' ' : '\n');
        }
    }


    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n+1, vector<int>(n+1, 0));

    while(m--){
        int u, v;
        cin >> u >> v;

        mat[u][v] = mat[v][u] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << mat[i][j] << (j<n ? ' ' : '\n');
        }
    }

    return 0;
}

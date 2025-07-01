#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin >> V;

    vector<vector<int>> mat(V, vector<int>(V, 0));

    for(int u = 1; u <= V; u++){
        int E;
        cin >> E;

        while(E--){
            int A;
            cin >> A;

            mat[u - 1][A - 1] = 1;
        }
    }

   for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout << mat[i][j] << (j+1 < V ? ' ' : '\n');
        }
    }
    
    return 0;
}

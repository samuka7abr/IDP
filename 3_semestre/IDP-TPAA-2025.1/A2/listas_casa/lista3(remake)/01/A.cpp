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

int main(){
    otim;
    int N;
    cin >> N;

    mat.assign(N + 1, vector<int>(N + 1, 0));

    for(int i = 1; i <= N; i++){
        int a;
        cin >> a;
 
        while(a--){
            int b;
            cin >> b;
 
            mat[i - 1][b - 1] = 1;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << mat[i][j] << (j + 1 < N ? ' ' : '\n');
        }
    }
    
    return 0;
}

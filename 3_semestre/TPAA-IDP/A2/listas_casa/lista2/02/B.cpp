#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, C;
    cin >> M >> C;
    
    vector<vector<int>> v(M);
    for(int i = 0; i < C; i++){
        int num;
        cin >> num;
        int idx = num % M;

        v[idx].push_back(num);
    }

    for(int i = 0; i < M; i++){
        cout << i << " -> ";

        for(int x : v[i]){
            cout << x << " -> ";
        }
        cout << "\\" << "\n"; 
    }

    return 0;
}

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

    vector<int> notas(N);
    for(int i = 0; i < N; i++){
        cin >> notas[i];
    }

    sort(notas.begin(), notas.end());

    for(int j = 0; j < notas.size(); j++){
        cout << notas[j] << '\n';
    }

    return 0;
}

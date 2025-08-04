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
const int MOD = 1000000007;

int solve(int N, const vector<int>& V, const vector<int>& P, int W) {
    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < N; ++i) {
        int peso = P[i];
        int valor = V[i];
        for (int w = W; w >= peso; --w) {
            dp[w] = max(dp[w], dp[w - peso] + valor);
        }
    }
    return dp[W];
}

int main(){
    otim;
    int N;
    cin >> N;
    vector<int> V(N), P(N);
    for (int i = 0; i < N; ++i){
        cin >> V[i];
    }

    for (int i = 0; i < N; ++i){
        cin >> P[i];
    } 
    int W;
    cin >> W;
    cout << solve(N, V, P, W) << "\n";
    return 0;
}

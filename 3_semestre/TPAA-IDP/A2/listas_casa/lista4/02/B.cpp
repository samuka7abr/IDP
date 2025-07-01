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

bool solve(int M, const vector<int>& coins) {
    vector<char> dp(M + 1, false);
    dp[0] = 1;
    for (int v : coins) {
        for (int j = M; j >= v; --j) {
            if (dp[j - v]) dp[j] = 1;
        }
    }
    return dp[M];
}

int main(){
    otim;
    int M, C;
    cin >> M >> C;
    vector<int> coins(C);
    for (int i = 0; i < C; ++i) cin >> coins[i];

    cout << (solve(M, coins) ? "SIM" : "NAO") << "\n";
    return 0;
}

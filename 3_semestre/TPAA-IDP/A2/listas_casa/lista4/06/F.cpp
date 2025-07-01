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

int solve(int L, int C, const vector<string>& grid) {
    vector<vector<int>> dp(L, vector<int>(C, 0));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
            } else if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                ll caminhos = 0;
                if (i > 0) caminhos += dp[i-1][j];
                if (j > 0) caminhos += dp[i][j-1];
                dp[i][j] = caminhos % MOD;
            }
        }
    }
    return dp[L-1][C-1] == 0 ? -1 : dp[L-1][C-1];
}

int main(){
    otim;
    int L, C;
    cin >> L >> C;
    vector<string> grid(L);
    for (int i = 0; i < L; ++i) {
        cin >> grid[i];
    }

    int ans = solve(L, C, grid);
    cout << ans << "\n";
    return 0;
}

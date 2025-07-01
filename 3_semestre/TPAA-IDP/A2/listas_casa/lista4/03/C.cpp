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

int solve(int M, const vector<int>& coins) {
    vector<int> dp(M + 1, INF_INT);
    dp[0] = 0;
    for (int v : coins) {
        for (int j = v; j <= M; ++j) {
            if (dp[j - v] != INF_INT)
                dp[j] = min(dp[j], dp[j - v] + 1);
        }
    }
    return dp[M] == INF_INT ? -1 : dp[M];
}

int main(){
    otim;
    int M, C;
    cin >> M >> C;
    vector<int> coins(C);
    for (int i = 0; i < C; ++i)
        cin >> coins[i];

    int ans = solve(M, coins);
    if (ans == -1)
        cout << "impossivel\n";
    else
        cout << ans << "\n";
    return 0;
}

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

vector<int64_t> solve(const vector<int>& qs) {
    int maxN = 0;
    for (int n : qs)
        if (n > maxN) maxN = n;

    vector<int64_t> dp(maxN + 1);
    if (maxN >= 0) dp[0] = 0;
    if (maxN >= 1) dp[1] = 1;
    for (int i = 2; i <= maxN; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    vector<int64_t> res;
    res.reserve(qs.size());
    for (int n : qs)
        res.push_back(dp[n]);
    return res;
}

int main(){
    otim;
    int T;
    cin >> T;
    vector<int> qs(T);
    for (int i = 0; i < T; ++i)
        cin >> qs[i];

    vector<int64_t> ans = solve(qs);
    for (auto x : ans)
        cout << x << '\n';

    return 0;
}

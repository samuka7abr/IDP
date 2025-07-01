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

int solve(int N, const vector<int>& h) {
    vector<ll> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < N; ++i) {
        ll c1 = dp[i-1] + abs(h[i] - h[i-1]);
        ll c2 = dp[i-2] + abs(h[i] - h[i-2]);
        dp[i] = min(c1, c2);
    }
    return dp[N-1];
}

int main(){
    otim;
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; ++i){
        cin >> h[i];
    }
    cout << solve(N, h) << "\n";
    return 0;
}

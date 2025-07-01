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

ll solve(int N, const vector<int>& C) {
    vector<vector<ll>> dp_score(N, vector<ll>(N, 0)), dp_disc(N, vector<ll>(N, 0));

    for (int len = 2; len <= N; ++len) {
        for (int l = 0; l + len - 1 < N; ++l) {
            int r = l + len - 1;
            ll takeL = C[l] + dp_disc[l+1][r];
            ll takeR = C[r] + dp_disc[l][r-1];
            dp_score[l][r] = max(takeL, takeR);

            if (len >= 3) {
                ll dropL = dp_score[l+1][r];
                ll dropR = dp_score[l][r-1];
                dp_disc[l][r] = max(dropL, dropR);
            } else {
                dp_disc[l][r] = 0;
            }
        }
    }
    return dp_score[0][N-1];
}

int main(){
    otim;
    int N;
    cin >> N;
    vector<int> C(N);
    for (int i = 0; i < N; ++i) cin >> C[i];

    cout << solve(N, C) << "\n";
    return 0;
}

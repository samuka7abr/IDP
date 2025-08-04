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
    ll K;
    cin >> N >> K;

    unordered_set<ll> us;
    us.reserve(N);

    while(N--){
        ll num;
        cin >> num;

        ll y = K - num;

        if(us.count(y)){
            cout << num << " " << y << endl;
            return 0;
        }

        us.insert(num);
    }

    cout << "Nao existe" << endl;
    return 0;
}

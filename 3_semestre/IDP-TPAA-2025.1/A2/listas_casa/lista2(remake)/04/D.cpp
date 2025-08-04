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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    ll K;
    cin >> N >> K;
 
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
 
    for(int i = 0; i < N; i++){
        ll num = A[i];
        ll resto = K - num;
        unordered_set<ll> us;
        us.reserve(N - i - 1);
 
        for(int j = i + 1; j < N; j++){
            ll y = A[j];
            ll z = resto - y;
 
            if(us.count(z)){
                cout << num << " " << y << " " << z << endl;
                return 0;
            }
            us.insert(y);
        }
    }
 
    cout << "Nao existe" << endl;
    return 0;
}

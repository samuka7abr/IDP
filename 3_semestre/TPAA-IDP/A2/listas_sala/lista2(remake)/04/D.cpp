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

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll num;
    for(int i = 0; i < N; i++){
        cin >> num;
        pq.push(num);
    }

    ll total = 0;

    while(pq.size() > 1){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();

        total += b;
        pq.push(a + b);
    }


    cout << total << endl;
    
    return 0;
}

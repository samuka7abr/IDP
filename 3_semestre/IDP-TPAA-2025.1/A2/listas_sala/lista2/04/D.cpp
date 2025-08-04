#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0; i < N; i++){
        ll x;
        cin >> x;
        pq.push(x);
    }

    ll totalCost = 0;
    while(pq.size() > 1){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        totalCost += b;
        pq.push(a + b);
    }

    cout << totalCost << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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

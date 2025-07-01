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

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
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        unordered_set<char> letras;
        for(int i = 0; i < N; i++){
            string linha;
            cin >> linha;

            for(char c : linha){
                letras.insert(c);
            }
        }

        cout << letras.size() << endl;
    }
    return 0;
}

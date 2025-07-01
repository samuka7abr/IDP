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
    int P;
    cin >> P;
    unordered_map<string,int> freq;
    string S;
    while(P--){
        cin >> S;
        int &cnt = freq[S];
        if(cnt == 0){
            cout << "OK\n";
            cnt = 1;
        } else {
            string t = S + to_string(cnt);
            cout << t << "\n";
            cnt++;
            freq[t] = 1;
        }
    }
    return 0;
}
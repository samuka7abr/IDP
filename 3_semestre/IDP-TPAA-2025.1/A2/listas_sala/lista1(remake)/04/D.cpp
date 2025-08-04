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
    otim
 
    int P, R;
    cin >> P >> R;
 
    multiset<int> low, high;
 
    for(int i = 0; i < P; i++){
        int c;
        cin >> c;
 
        if((int)low.size() < R){
            low.insert(c);
        }else{
 
            auto it_max_low = prev(low.end());
 
            if(c < *it_max_low){
                high.insert(*it_max_low);
                low.erase(it_max_low);
                low.insert(c);
            }else{
                high.insert(c);
            }
        }
 
        cout << *prev(low.end()) << endl;
        }
 
    return 0;
}
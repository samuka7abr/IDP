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

    priority_queue<pair<int, string>> pq;

    for(int i = 0; i < N; i++){
        string name;
        int tempo;
        cin >> name >> tempo;

        pq.push({tempo, name});
    }

    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        cout << top.second << " "<<top.first << endl;

        top.first = top.first / 2;
        
        if(top.first < 1){
            continue;
        }else{
            pq.push({top.first, top.second});
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    
    priority_queue<pair<int, string>> pq;

    while(N--){
        string nome;
        int tempo;
        cin >> nome >> tempo;
        pq.push({tempo, nome});
    }

    while(!pq.empty()){
        auto [t, n] = pq.top();
        pq.pop();
        
        cout << n << " " << t << endl;
        
        int t2 = t / 2;
        
        if(t2 >= 1){
            pq.push({t2, n});
        }
    }

    return 0;
}

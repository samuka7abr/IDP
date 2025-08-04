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

    set<string> s;

    while(N--){
        int M;
        cin >> M;
        for(int i = 0; i < M; i++){
            string ing;
            cin >> ing;

            if(s.count(ing)){
                cout << ing << " ja tem" << endl;
            }else{
                s.insert(ing);
                cout << "adicionando " << ing << endl;
            }
        }
    }

    cout << "Itens do churrasco:" << endl;

    for(auto item : s){
        cout << item << endl;
    }

    return 0;
}

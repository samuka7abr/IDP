#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int P, R;
    cin >> P >> R;

    multiset<int> s;
    multiset<int>::iterator it = s.end();

    for(int i = 0; i < P; i++){
        int x;
        cin >> x;

        auto inserted = s.insert(x);
        if((int)s.size() <= R){
            it = prev(s.end());
        }else{
            if(x < *it) --it;
        }

        cout << *it << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    ull mask = 0;
    int a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        mask |= (1ULL << a);
    }
    cout << mask << "\n";

    return 0;
}

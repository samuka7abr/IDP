#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    while(N--){
        string p1, p2;
        cin >> p1 >> p2;

        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());

        if(p1 == p2){
            cout << "ANAGRAMAS" << endl;
        }else{
            cout << "DIFERENTES" << endl;
        }
        
    }

    return 0;   
}

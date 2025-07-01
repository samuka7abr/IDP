#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, B;
    cin >> N >> B;
    int mask = ~(1 << B);
    while(N--){
        int num;
        cin >> num;
        num &= mask;

        cout << num << endl;
    }

    return 0;
}
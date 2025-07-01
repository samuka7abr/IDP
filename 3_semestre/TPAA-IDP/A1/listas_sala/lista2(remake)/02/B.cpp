#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned int N;
    cin >> N;

    unsigned int result = 0;

    for(int i = 0; i < 32; i++){
        result = (result << 1) | (N & 1);
        N >>= 1;
    }

    cout << result << endl;

    return 0;
}
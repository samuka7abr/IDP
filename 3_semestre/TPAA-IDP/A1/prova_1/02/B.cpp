#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int D;
    while (true) {
        cin >> D;
        if (D == -1) break;
        string s;
        cin >> s;
        ll A = 0, B = 0;
        for (int i = 0; i < D; ++i) {
            int d = s[i] - '0';
            if (i % 2 == 0) A += d;
            else           B += d;
        }
        ll S = A - B;
        bool div11 = (S % 11 == 0);
        cout << s << ": "
             << A << " - " << B << " = " << S
             << " - " << (div11 ? "sim" : "nao") << "\n";
    }

    return 0;
}

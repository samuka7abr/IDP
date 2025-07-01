#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    set<char> s;  

    for(char c : input){
        s.insert(c);
    }


    for(char ch : s){
        cout << ch;
    }
    cout << endl;
    return 0;
}

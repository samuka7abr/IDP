#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        string R, S;
        cin >> R >> S;
        if(R.size() != S.size()){
            cout << "DIFERENTES\n";
            continue;
        }
        unordered_map<char,int> freq;
        freq.reserve(R.size());
        for(char c : R) freq[c]++;
        bool ok = true;
        for(char c : S){
            auto it = freq.find(c);
            if(it == freq.end() || --it->second < 0){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "ANAGRAMAS" << endl;
        }else{
            cout << "DIFERENTES" << endl;
        }
    }
    return 0;
}

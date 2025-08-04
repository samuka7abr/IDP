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
        set<char> S;

        string gramas;
        cin >> gramas;

        bool tem = true;
        for(char c : gramas){
            if(!S.insert(c).second){
                tem = false;
                break;
            }
        }

        if(tem){
            cout << "STRONGRAMA" << endl;
        }else{
            cout << "WEAKORD" << endl;
        }
    }


    return 0;
}

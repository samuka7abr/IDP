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
        multiset<char> s;
        set<char> ta;

        string pedra, verifica;
        cin >> pedra >> verifica;

        for(char c : pedra){
            s.insert(c);
        }

        int count = 0;
        
        for(char ch : verifica){
            auto r = ta.insert(ch);
            if(r.second){
                count += s.count(ch);
            }

            
        }

        cout << "Contem " << count << " pedras negociaveis" << endl;
    }


    return 0;
}
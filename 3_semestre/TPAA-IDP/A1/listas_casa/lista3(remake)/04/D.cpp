#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<string>norte, sul, leste, oeste; /*várias pilhas*/
    string dir;
    string token;

    while(cin >> token && token != "0"){
        if(token[0] == 'B'){
            if(dir == "N"){ /*dá os pushs
                conforme a dir*/
                norte.push(token);
            }else if(dir == "S"){
                sul.push(token);
            }else if(dir == "L"){
                leste.push(token);
            }else if(dir == "O"){
                oeste.push(token);
            }else{
                dir = token;
            }
        }
    }

    bool primeiro = true; /*booleana para dar pop
    e registrar que o elemento do topo foi removido*/
    while(!norte.empty() || !sul.empty() || !leste.empty() || !oeste.empty()){
        if(!norte.empty()){
            cout << norte.front(); /*printa o front*/
            norte.pop(); /*remove o front*/
            primeiro = false;/*declara que agora, não é
            mais o antigo primeiro que está
            na frente*/
        }
        else if(!sul.empty()){
            cout << sul.front();
            sul.pop();
            primeiro = false;
        }
        else if(!leste.empty()){
            cout << leste.front();
            leste.pop();
            primeiro = false;
        }
        else if(!oeste.empty()){
            cout << oeste.front();
            oeste.pop();
            primeiro = false;
        }
    }

    return 0;
}
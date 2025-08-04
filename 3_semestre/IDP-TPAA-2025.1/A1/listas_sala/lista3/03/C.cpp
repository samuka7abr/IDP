#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    queue<int> q;
    for (int i = N; i >= 1; i--){
        q.push(i);
    }
    
    vector<int> descartadas;
    while(q.size() > 1){
        descartadas.push_back(q.front());
        q.pop();
        int carta = q.front();
        q.pop();
        q.push(carta);
    }
    
    cout << "Descarte: "; 
    if(!descartadas.empty()){
        cout << descartadas[0];
        for (size_t i = 1; i < descartadas.size(); i++){
            cout << ", " << descartadas[i];
        }
    }
    cout << "\n";
    
    cout << "Ultima carta: " << q.front() << "\n";
    
    return 0;
}

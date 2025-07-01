#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool compare(string a, string b){
    if(a.size() == b.size()){
        return a < b;
    }
    return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<string> livros(N);
    for(int i = 0; i < N; i++){
        cin >> livros[i];
    } 

    sort(livros.begin(), livros.end(), compare);

    for(string titulo : livros){
        cout << titulo << endl;
    }
    return 0;
}
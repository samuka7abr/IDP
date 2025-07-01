#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<string, string> &player1, const pair<string, string> &player2){
    /*essa função serve de condição de ordenação.
    se o p1.second(tempo) for diferente do p2,
    retorna o p1.second sendo maior que o p2 em
    booleano. ou seja: se o p2 for maior,
    retorna zero e seta o sort para retornar
    o contrário*/
    if(player1.second != player2.second){
        return player1.second  > player2.second;
    }
    /*porfim, retorna o p1.first sendo maio que 
    o p2(nome em ordem alfabetica)*/
    return player1.first > player2.first; /*só retorna em caso de 
    empate de tempo*/
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long N;
    cin >> N;

    string nick, tempo;
    vector<pair<string, string>> players; /*vetor de vetores [[], [], [] ...] */

    for(long long i = 0; i < N; i++){
        cin >> nick >> tempo;
        players.push_back(make_pair(nick, tempo)); /*adiciona ao vetor como par
        ou seja: a posição 1, vai ter um vetor com duas posições(nick e tempo)*/
        //dá pra usar emplace_back(nick, tempo)
    }

    sort(players.begin(), players.end(), compare); /*ordena o inicio e fim do vetor
    com a condição estipulada pela função compare
    (pode ser feito com lambda para usar valores dentro do escopo da main)*/

    for(long long i = 0; i < N; i++){
        cout << i + 1 << ". " <<players[i].second << " - " <<players[i].first << endl;
    }
}
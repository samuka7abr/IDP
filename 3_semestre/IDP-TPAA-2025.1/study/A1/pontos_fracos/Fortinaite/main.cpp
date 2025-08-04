#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool comparator(const pair<string, string>& player1, const pair<string, string>& player2){
    if(player1.second != player2.second){
        return player1.second > player2.second;
    }

    return player1.first > player2.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;

    string nick, tempo;
    vector<pair<string, string>>players;
    for(ll i = 0; i < N; i++){
        cin >> nick >> tempo;
        players.push_back({nick, tempo});
    }

    sort(players.begin(), players.end(), comparator);

    for(ll i = 0; i < players.size(); i++){
        cout << i + 1 << ". " << players[i].second << " - " << players[i].first << endl;
    }


    return 0;
}
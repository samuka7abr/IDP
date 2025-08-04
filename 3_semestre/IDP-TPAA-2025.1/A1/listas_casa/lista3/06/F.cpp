#include <bits/stdc++.h>
using namespace std;

struct Player {
    string name;
    string timeStr;  
    int totalSeconds; 

    static int convertToSeconds(const string &timeStr) {
        int minutes, seconds;
        char colon; 
        istringstream iss(timeStr);
        iss >> minutes >> colon >> seconds;
        return minutes * 60 + seconds;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int J;
    cin >> J;
    vector<Player> players(J);
    
    for (int i = 0; i < J; i++){
        cin >> players[i].name >> players[i].timeStr;
        players[i].totalSeconds = Player::convertToSeconds(players[i].timeStr);
    }
    
    sort(players.begin(), players.end(), [](const Player &a, const Player &b) {
        if(a.totalSeconds != b.totalSeconds) {
            return a.totalSeconds > b.totalSeconds; 
        }
        return a.name > b.name;
    });
    
    for (int i = 0; i < J; i++){
        cout << i+1 << ". " << players[i].timeStr << " - " << players[i].name;
        if(i < J-1) cout << "\n";
    }
    
    return 0;
}

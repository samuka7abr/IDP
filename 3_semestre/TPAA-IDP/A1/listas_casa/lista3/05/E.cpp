#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long H;
    cin >> N >> H;
    vector<long long> exercicios(N);
    long long maxEx = 0;
    for (int i = 0; i < N; i++){
        cin >> exercicios[i];
        maxEx = max(maxEx, exercicios[i]);
    }

    auto sessoesNecessarias = [&](long long k) -> long long {
        long long sessoes = 0;
        for (int i = 0; i < N; i++){
            sessoes += (exercicios[i] + k - 1) / k;
        }
        return sessoes;
    };

    long long low = 1, high = maxEx, ans = high;
    while(low <= high){
        long long mid = (low + high) / 2;
        long long totalSessoes = sessoesNecessarias(mid);
        if(totalSessoes <= H){ 
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    
    cout << ans << "\n";
    return 0;
}
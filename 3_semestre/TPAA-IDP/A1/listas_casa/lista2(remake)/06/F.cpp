#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        vector<int>arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        int S;
        cin >> S;

        int left = 0, right = N - 1;
        bool found = false;

        while(left < right){
            int currentSum = arr[left] + arr[right];
            if(currentSum == S){
                found = true;
                break;
            }else if(currentSum < S){
                left++;
            }else{
                right--;
            }

            if(found){
                cout << "SIM" << endl;
            }else{
                cout << "NAO" << endl;
            }
        }
    }

    return 0;
}
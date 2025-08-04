#include <iostream>
#include <string>
using namespace std;

int main() {
    int D;
    while (cin >> D && D != -1) {
        string N;
        cin >> N;
        int sum = 0;
        for (char c : N) {
            sum += c - '0';
        }
        cout << sum << " ";
        if (sum % 3 == 0)
            cout << "sim";
        else
            cout << "nao";
        cout << endl;
    }
    return 0;
}
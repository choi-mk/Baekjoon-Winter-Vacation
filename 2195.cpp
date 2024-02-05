#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int Ans = 0;
    string S, P;
    cin >> S >> P;
    for (int i = 0; i < P.length(); i++) {
        int Length = 1;
        for (int j = 0; j < S.length(); j++) {
            if (P[i] == S[j]) {
                int Count = 1;
                for (int k = 1;; k++) {
                    if (i + k >= P.length() || j + k >= S.length()) break;
                    if (P[i + k] == S[j + k]) Count++;
                    else break;
                }
                Length = max(Length, Count);
            }
        }
        Ans++;
        i += Length - 1;
    }
    cout << Ans;
}

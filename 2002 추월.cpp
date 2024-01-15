#include <iostream>
#include <string>
#include <map>

using namespace std;
int N;
map<string, int> Start;
int End[1001];
int Answer = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        Start.insert(make_pair(S, i));
    }
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        End[i] = Start[S];
    }
    
    for (int i = 0; i < (N - 1); i++) {
        for (int j = (i + 1); j < N; j++) {
            if (End[i] > End[j]) {
                Answer++;
                break;
            }
        }
    }
    
    cout << Answer << "\n";

    return 0;
}

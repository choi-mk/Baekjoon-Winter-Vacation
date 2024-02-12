#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int min_day = 0;
    int total = 0;
    for (char c : S) {
        if (c == '(') total++;
        else total--;
        min_day = max(min_day, abs(total));
    }

    if (total == 0) cout << min_day << endl; 
    else cout << -1 << endl;
    

    return 0;
}

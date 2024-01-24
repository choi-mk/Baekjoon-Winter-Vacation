#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> map(n+1, vector<int>(n+1, 0));
    vector<vector<int>> answer(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            answer[i][j] = (j == 0 ? answer[i-1][j] : max(answer[i-1][j-1], answer[i-1][j])) + map[i][j];
        }
    }

    cout << *max_element(answer[n].begin(), answer[n].end());

    return 0;
}

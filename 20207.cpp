#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> calendar(366, 0);

    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;

        for (int j = s; j <= e; ++j) {
            calendar[j]++;
        }
    }

    int row = 0;
    int col = 0;
    int ans = 0;
    for (int i = 0; i < 366; ++i) {
        if (calendar[i] != 0) {
            row = max(row, calendar[i]);
            col++;
        } else {
            ans += row * col;
            row = 0;
            col = 0;
        }
    }
    ans += row * col;
    cout << ans << endl;

    return 0;
}

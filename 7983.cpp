#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> day;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        day.push_back({b - a + 1, a, b});
    }

    sort(day.begin(), day.end(), [](const auto &a, const auto &b) {
        return tie(get<2>(a), get<1>(a)) > tie(get<2>(b), get<1>(b));
    });

    int now = get<0>(day[0]);
    for (int i = 1; i < n; ++i) {
        int must_start, need, must_finish;
        tie(must_start, need, must_finish) = day[i];
        if (now > must_finish) {
            now = must_start;
        } else {
            now = now - need;
        }
    }

    cout << now - 1;

    return 0;
}

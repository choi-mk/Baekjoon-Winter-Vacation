#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int x, int y) {
    return x > y;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> t(N);
    vector<int> time(M, 0);

    for (int i = 0; i < N; i++) cin >> t[i];

    sort(t.begin(), t.end(), compare);

    for (int i = 0; i < N; i++) {
        int minIdx = 0;
        for (int j = 1; j < M; j++) {
            if (time[j] < time[minIdx]) minIdx = j;
        }
        time[minIdx] += t[i];
    }

    int maxTime = *max_element(time.begin(), time.end());

    cout << maxTime << endl;

    return 0;
}

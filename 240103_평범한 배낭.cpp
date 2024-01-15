// https://www.acmicpc.net/problem/12865
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> weight(n);
    vector<int> value(n);

    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            matrix[j][i] = matrix[j][i - 1];
            if (weight[i - 1] <= j) {
                matrix[j][i] = max(matrix[j][i], matrix[j - weight[i - 1]][i - 1] + value[i - 1]);
            }
        }
    }

    cout << matrix[m][n] << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> diff;
    for (int i = 0; i < n - 1; ++i) {
        diff.push_back(arr[i + 1] - arr[i]);
    }

    sort(diff.begin(), diff.end());

    for (int i = 0; i < k - 1; ++i) diff.pop_back();
    
    for (int i = 0; i < k; ++i) diff.push_back(1);

    int sum = 0;
    for (int d : diff) sum += d;
    cout << sum;

    return 0;
}

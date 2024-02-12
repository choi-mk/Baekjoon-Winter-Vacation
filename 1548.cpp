#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) cin >> data[i];
    sort(data.begin(), data.end());

    int result = 2;
    if (n > 2) {
        for (int start = 0; start < n - 2; ++start) {
            int end = start + 2;
            while (true) {
                if (data[start] + data[start + 1] > data[end]) {
                    result = max(result, end - start + 1);
                    ++end;
                    if (end == n) break;
                } 
                else break;
            }
        }
    } 
    else result = n;
    

    cout << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	string S, T;
	cin >> S >> T;
	while (1) {
		if (T[T.size() - 1] == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
		if (T.size() == S.size()) {
			if (T == S) cout << 1;
			else cout << 0;
			break;
		}
	}
	return 0;
}
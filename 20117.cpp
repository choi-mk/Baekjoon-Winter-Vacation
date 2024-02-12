#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N, i, avg=0;
	int hoban[100000] = {};

	cin >> N;
	for (i = 0; i < N; i++) cin >> hoban[i];

	sort(hoban, hoban + N);

	if (N % 2){
		for (i = 0; i < N/2; i++)
			avg += hoban[N - 1 - i] * 2;
		avg += hoban[i];
	}
	else{
		for (i = 0; i < N / 2; i++)
			avg += hoban[N - 1 - i] * 2;
	}

	cout << avg;

	return 0;
}
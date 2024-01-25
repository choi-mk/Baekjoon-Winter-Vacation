#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N; int K;
    cin >> N >> K;
    int height[300001];
    for(int i=0; i<N; i++) cin >> height[i];

    int *gap = new int[N-1];
    for(int i=0; i<N-1; i++){
        gap[i] = height[i+1]-height[i];
    }

    sort(gap, gap+N-1);
    int cost = 0;
    for(int i=0; i<N-K; i++) cost += gap[i];

    cout << cost;

    delete[] gap;
    return 0;
}

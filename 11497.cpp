#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;


int main(){
    int T, N;
    int L[100001];
    int Max[10001];
    int arr[100001];

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        for(int j=0; j<N; j++) cin >> L[j];
        sort(L, L+N);
        
        int left = L[0]; int right= L[1];
        int max = abs(left-right);
        int temp;


        for(int k=2; k<N; k++){
            temp = abs(left-L[k]);
            left = L[k++];
            max = (max > temp) ? max : temp;


            temp = abs(right-L[k]);
            right = L[k];
            max = (max > temp) ? max : temp;


            if(k == N-2){ // 1개 남음
                temp = abs(left-L[++k]);
                max = (max > temp) ? max : temp;

                temp = abs(right-L[k]);
                max = (max > temp) ? max : temp;
            }
            else if(k == N-1){ // 안 남음
                temp = abs(left-right);
                max = (max > temp) ? max : temp;

            }
        }
        
        Max[i] = max;
    }

    for(int i=0; i<T; i++) printf("%d\n", Max[i]);
}
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    int *A = new int[N+1]();
    int *B = new int[N+1];
    for(int i=0; i<N; i++) scanf("%d", &B[i]);

    int DoubleCnt;
    int maxDblCnt = 0;
    int PlusCnt = 0;
    for(int i=0; i<N; i++){
        DoubleCnt=0;
        while(B[i]){
            if(B[i]%2==0){
                B[i]=B[i]/2;
                DoubleCnt++;
            }
            else{
                B[i]-=1;
                PlusCnt++;
            }
        }
        if(maxDblCnt<DoubleCnt) maxDblCnt = DoubleCnt;
        
    }

    int opCnt = maxDblCnt+PlusCnt;

    printf("%d", opCnt);

}
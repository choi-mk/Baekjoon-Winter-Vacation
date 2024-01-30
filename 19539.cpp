#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    int* h = new int[N];
    int totalH = 0;

    for(int i=0; i<N; i++){
        scanf("%d", &h[i]);
        totalH+=h[i];
    }

    if(totalH%3!=0){
        printf("NO");
        return 0;
    }

    int total2 = totalH/3;
    for(int i=0; i<N; i++){
        total2-=h[i]/2;
    }
    if(total2<=0) printf("YES");
    else printf("NO");

    return 0;
}

/* 1번째 풀이
3으로 나눴을 때 나머지를 구해서, 나머지가 1인 것과 2인 것의 개수가 같으면 맞다고 판단
-너무 일차원적인 생각 아니냐ㅋㅋㅠ
*/

/* 2번째 풀이
정렬 후, 작은 것부터 해결
나머지가 1이면 그 다음 것들 중에서 2빼고, 2이면 그 다음 것들 중에서 1 뺌
그렇게 하나씩 0으로 만든 후 남은 1개가 3의 배수면 맞다고 판단
- 복잡하기도 하지만, 전체적으로 적용되는 규칙을 더 파악했어야 할듯
    if(totalH%3!=0){
        printf("NO");
        return 0;
    }

    if(N==1 && totalH%3==0){
        printf("YES");
        return 0;
    }
    
    sort(h, h+N);
    bool fail; int less;
    for(int i=0; i<N-1; i++){
        h[i] = h[i]%3;

        if(h[i]!=0){
            less = 3-h[i];
            fail = true;
            for(int j=i+1; j<N; j++){
                if(h[j]>=less){
                    h[j]-=less;
                    fail = false;
                    break;
                }
            }
            if(fail){
                printf("NO");
                return 0;
            }
        }
    }
    if(h[N]%3!=0) printf("NO");
    else printf("YES");
*/

/* 3번째 풀이
총 필요 길이는 3의 배수
총 필요 날짜를 구할 수 있음 -- 놓쳤던 부분
즉, 1과 2의 총 개수 k를 알 수 있음

효율적으로 가려면, 더 큰 수인 2부터 해결
2가 k번 들어가기만 하면 됨
*/
#include<iostream>
#include<algorithm>
using namespace std;
long long a[1001];

int main(){
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }

    long long temp;
    for(int i=0; i<m; i++){
        sort(a, a+n);
        temp=a[0]+a[1];
        a[0]=temp;
        a[1]=temp;
    }

    long long sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
    }
    
    printf("%lld",sum);
    return 0;
}
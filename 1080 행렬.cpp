#include<iostream>
#include<cstdio>
using namespace std;
int a[51][51];
int b[51][51];
void oper(int i1, int j1){
    for(int i=i1; i<i1+3; i++){
        for(int j=j1; j<j1+3; j++){
            a[i][j]=1-a[i][j];
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&a[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&b[i][j]);
        }
    }

    int result=0;
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-2; j++){
            if(a[i][j]!=b[i][j]){
                result++;
                oper(i,j);
            } 
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]!=b[i][j]){
                result=-1;
                i=n;
                break;
            }
        }
    }
    
    printf("%d",result);
    return 0;
}
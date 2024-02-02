#include <iostream>
#include <cstdio>

using namespace std;

int coin[110][110];

void Reverse(int y,int x)
{
    for(int i=0;i<=y;i++){
        for(int j=0;j<=x;j++){
            coin[i][j]=1-coin[i][j]; 
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&coin[i][j]);
        }
    }
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        for(int j= m-1;j>=0;j--){
            if(coin[i][j]==1){
                cnt++;
                Reverse(i,j);
            }
        }
    }
    cout << cnt;
    return 0;
}

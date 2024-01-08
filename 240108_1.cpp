//https://www.acmicpc.net/problem/10844

#include <iostream>
#include <vector>
using namespace std; 

int mod=1e9;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> result(n+1, vector<int>(10, 0));

    for (int i=1; i<=9; i++){
        result[1][i]=1;
    }
    for (int i=2; i<=n; i++){
        for (int j=0; j<10; j++){
            if (j>0) result[i][j]=(result[i][j]+result[i-1][j-1])%mod;
            if (j<9) result[i][j]=(result[i][j]+result[i-1][j+1])%mod;
        }
    }
    long long answer=0;
    for (int i=0; i<10; i++){
        answer+=result[n][i];
    }
    cout<<answer%mod;
}


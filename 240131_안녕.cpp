//https://www.acmicpc.net/problem/1535
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> happy(n+1,0);
    vector<int> sad(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>sad[i];
    }
    for(int i=1; i<=n; i++){
        cin>>happy[i];
    }


    vector<vector<int>> Sejun(n+1, vector<int>(101,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<101; j++){
            if(j<sad[i]) Sejun[i][j]=Sejun[i-1][j];
            else Sejun[i][j]=max(Sejun[i-1][j], Sejun[i-1][j-sad[i]]+happy[i]);
        }
    }
    cout<<Sejun[n][99];


}
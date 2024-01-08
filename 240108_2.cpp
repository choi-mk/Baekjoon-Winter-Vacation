//https://www.acmicpc.net/problem/11057

#include <iostream>
#include <vector>
using namespace std; 

int main(){
    int n;
    cin>>n;
    vector<vector<int>> result(n+1, vector<int>(10, 0));
    for (int i=0; i<10; i++){
        result[1][i]=1;
    }
    for (int i=2; i<=n; i++){
        for (int j=0; j<10; j++){
            for (int k=0; k<10; k++){
                if (k<=j){
                    result[i][j]+=result[i-1][k];
                }
            }
            result[i][j]=result[i][j]%10007;
        }
    }

    int answer=0;
    for (int i=0; i<10; i++){
        answer+=result[n][i];
    }
    cout<<answer%10007;

}